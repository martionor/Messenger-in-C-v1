# Messenger-in-C-v1
- Messaging coded in C language V1
- Single thread server client communication
- Menu options: Send message, Read messages, Quit
- Read messages ask for simple password.
- For now server saves only 10 messages at a time.

This is Version 1, focusing on basic client–server communication and message storage.

# Compile the client-side messenger
gcc main.c client.c menu.c message.c -o messenger

# Compile the server
gcc server.c -o server

# Messenger pictures:
<img width="425" height="484" alt="image" src="https://github.com/user-attachments/assets/f0bbb775-4fee-4500-a73c-3c01c7bc5e42" />

## Read messages password is incorrect
<img width="527" height="385" alt="image" src="https://github.com/user-attachments/assets/184fa2a7-5307-44a8-b206-29a7e88c48b5" />

## Read messages with correct password
<img width="646" height="382" alt="image" src="https://github.com/user-attachments/assets/558e2ecb-fd93-47ff-bd97-c1ff9597db5c" />

# Server side pictures
<img width="518" height="307" alt="image" src="https://github.com/user-attachments/assets/c3db9e73-0387-4018-811e-f69b4fe15e00" />



