#ifndef SERVER_H
#define SERVER_H

void start_server();
int accept_client(int server_fd);
int setup_server();

#endif