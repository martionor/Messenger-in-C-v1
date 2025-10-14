#ifndef SERVER_H
#define SERVER_H

#define MSG_SIZE 512
#define MAX_MESSAGES 10

struct message_packet {
    int length;
    char content[MSG_SIZE];
};
void start_server();
int accept_client(int server_fd);
int setup_server();
void store_message(const char *buffer);
void send_stored_messages(int new_socket);
int check_password(const char *received_pass);

#endif