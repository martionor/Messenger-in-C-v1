#include <stdio.h>
#include "menu.h"
#include "message.h"
#include "client.h"
#include "menu.h"

void open_menu(){
    char menu_choice[10];
    struct write_message msg;
    
    while (1) {
            printf("\n Menu \n");
            printf("1 - Send message \n");
            printf("2 - Read messages (TODO) \n");
            printf("0 - Exit\n");
            printf("Select option: ");
            
            fgets(menu_choice, sizeof(menu_choice), stdin);
        
            switch (menu_choice[0]){
                case '1':
                    create_message(&msg);
                    display_message(&msg);
                    send_message_to_ip(&msg); // to client.c
                    break;
                case '2':
                    printf("Reading messages...\n");
                    break;
                case '0':
                    printf("Goodbye\n");
                    return;
                default:
                    printf("Invalid option. Choose 1,2,0.\n");
            }
    }
}