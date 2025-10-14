#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "server.h"


#define PORT 8080


char messages[MAX_MESSAGES][MSG_SIZE];
int message_count = 0;

int main() {
    start_server();
    return 0;
}

//Setting up the socket
int setup_server(){
    int server_fd;
    struct sockaddr_in address;

    server_fd = socket(AF_INET, SOCK_STREAM,0);
    if (server_fd < 0){
        perror("Socked failed");
        exit(EXIT_FAILURE);
    }


    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if(listen(server_fd, 5)<0){
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d \n", PORT);
    return server_fd;
}

//Handles client connection
int accept_client(int server_fd){
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024]={0};

    int new_socket = accept(server_fd,(struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (new_socket<0){
        perror("Accept failed");
        return 0;
    }

    read(new_socket, buffer, sizeof(buffer));

    if (strncmp(buffer, "READ_MESSAGES:", 14) == 0) {
        char *received_pass = buffer+14;//After :
        if (!check_password(received_pass)){
            char *msg = "Acces denied: password incorrect. \n";
            send(new_socket, msg, strlen(msg),0);
        }else{
            send_stored_messages(new_socket);
        }
    }else{
        store_message(buffer);
    }
       
    close(new_socket);
    return 0;
}

void start_server(){
    int server_fd = setup_server();

    while (1){
        accept_client(server_fd);
    }

    close(server_fd);
}

//Storing messages
void store_message(const char *buffer){
    strncpy(messages[message_count % MAX_MESSAGES], buffer, MSG_SIZE);
    printf("Message number: %d\n", (message_count % MAX_MESSAGES) + 1);
    printf("Received message: %s\n", buffer);
    message_count++;
}

//Read stored messages
void send_stored_messages(int new_socket){
    // Client requested stored messages
    char all_messages[MSG_SIZE * MAX_MESSAGES] = "";
    int start = (message_count > MAX_MESSAGES) ? (message_count - MAX_MESSAGES) : 0;
    
    if (message_count == 0) {
        strcpy(all_messages, "No messages stored yet.\n");
    }else{
        for(int i = start; i< message_count; i++){
            strcat(all_messages, messages[i % MAX_MESSAGES]);
            strcat(all_messages, "\n----\n");
        }
    }
    send(new_socket, all_messages, strlen(all_messages),0);
}


int check_password(const char *received_pass){
    const char *password = "password";

    //Remove newline characters
    char clean_pass[64];
    strncpy(clean_pass, received_pass, sizeof(clean_pass));
    clean_pass[strcspn(clean_pass, "\r\n")] = 0;

    if (strcmp(clean_pass, password)==0){
        return 1; //Correct
    }else{
        return 0; //failed
    }
}