#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "client.h"
#include "server.h"

void send_message_to_ip(struct write_message *msg){
        int sock = 0;
        struct sockaddr_in serv_addr;
        char message [255];
        
        snprintf(message, sizeof(message), "From %s\nTo: %s\nMessage: %s", msg->name, msg->to_who, msg->subject);
        
        //Create socket
        sock = socket(AF_INET, SOCK_STREAM,0);
        if (sock < 0){
            perror("Socket creation error");
            return;
        }
        
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(8080); //Same as server port
        
        //Convert IP txt to binary 
        //Change ip to servers ip
        if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <=0){
            perror("Invalid address");
            return;
        }
        
        //Connect to server
        if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0){
            perror("Connection failed");
            close(sock);
            return;
        }
        
        //Send message
        send(sock, message, strlen(message),0);
        printf("Message sent to server \n");
        
        //Close socket
        close(sock);
}

//Getting messages from server
void request_messages_from_server(const char *password) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char command[] = "READ_MESSAGES";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return;
    }

    
    // Send request for messages
    snprintf(buffer, sizeof(buffer), "%s:%s", command, password);
    send(sock, buffer, strlen(buffer), 0);

    // Receive all messages from server
    read(sock, buffer, sizeof(buffer));
    printf("\n--- Stored Messages ---\n%s\n", buffer);

    close(sock);
}
