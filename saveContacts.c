#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contactDefns.h"

void saveContacts(struct contact_data **record, int k){
    struct contact ptr;
    int i;
    FILE *fptr;
    remove("myContactsList.db");
    fptr = fopen("myContactsList.db", "w");

    for(i = 0; i < k; i++){
        fseek(fptr, 0, SEEK_END);
        ptr.phone_number = (*record)[i].phone_number;
        ptr.first_name_posn = sizeof(struct contact) + ftell(fptr);
        ptr.last_name_posn = ptr.first_name_posn + strlen((*record)[i].first_name) + !!(*record)[i].first_name[0];
        ptr.company_name_posn = ptr.last_name_posn + strlen((*record)[i].last_name) + !!(*record)[i].last_name[0];
        ptr.email_posn = ptr.company_name_posn + strlen((*record)[i].company_name) + !!(*record)[i].company_name[0];
        ptr.next = ptr.email_posn + strlen((*record)[i].email) + !!(*record)[i].email[0];
        if(!(*record)[i].first_name[0]){
            ptr.first_name_posn = 0;
        }
        if(!(*record)[i].last_name[0]){
            ptr.last_name_posn = 0;
        }
        if(!(*record)[i].company_name[0]){
            ptr.company_name_posn = 0;
        }
        fwrite(&ptr, sizeof(struct contact), 1, fptr);
    
        fwrite((*record)[i].first_name, strlen((*record)[i].first_name) + !!(*record)[i].first_name[0], 1, fptr);
        fwrite((*record)[i].last_name, strlen((*record)[i].last_name) + !!(*record)[i].last_name[0], 1, fptr);
        fwrite((*record)[i].company_name, strlen((*record)[i].company_name) + !!(*record)[i].company_name[0], 1, fptr);
        fwrite((*record)[i].email, strlen((*record)[i].email) + !!(*record)[i].email[0], 1, fptr);
    }
    fclose(fptr);
    return;
}
