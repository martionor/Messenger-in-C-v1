#ifndef CLIENT_H
#define CLIENT_H

#include "message.h"

void send_message_to_ip(struct write_message *msg);
void request_messages_from_server(const char *password);

#endif