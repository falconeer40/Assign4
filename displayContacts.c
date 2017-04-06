#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contactDefns.h"

int displayContacts(int k, struct contact_data **record){
    int current_loc;
    char action[10];
    current_loc = 0;
    action[0] = '\0';

    printList(*record, current_loc, k);
    do{
       action[0] = '\0';
       printf("Action: ");
       fgets(action,10,stdin);
       if(strlen(action) > 0){
           action[strlen(action) - 1] = '\0';
       }
       if(action[0] == '+'&& current_loc - k <= 5){
           current_loc++;
           printList(*record, current_loc, k);
       }else if(action[0] == '-'&& current_loc - k <= 5){
           current_loc--;
           printList(*record, current_loc, k);
       }else if((atoi(action) - 1) < k && (atoi(action) - 1) >= 0){
           printf("hello");
           k = contactDetails(record, atoi(action) - 1, k);
           printList(*record, current_loc, k);
       }else if(action[0] == 'A'){
           k = addContact(record,k);
           printList(*record, current_loc, k);
       }
    }while(action[0] != 'X'); 
    return k;
}
