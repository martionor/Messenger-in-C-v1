#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "client.h"

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