#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "server.h"


#define PORT 8080

int main() {
    start_server();
    return 0;
}

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

    //Checking if message is for the name we use 
    //Uncomment to use
    /* char recipient[24]= "Martin";

    if (strstr(buffer, recipient) != NULL){
        printf("Received message: %s\n", buffer);
    }else {
        printf("Message is not for you\n");
    } */
    
    // Printing all messages
    printf("Received message: %s\n", buffer);

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