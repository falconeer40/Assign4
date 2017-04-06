#include "contactDefns.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int loadContacts(int k, struct contact_data **record)
{
    struct contact temp;
    int i;
    int j;
    char data[4][101];
    FILE *fptr;

    fptr = fopen("myContactsList.db", "a+");
    j = 0;
    j = fread(&temp, sizeof(struct contact), 1, fptr);
    if(!j){
        return 0;
    }

    do{
        *record = realloc(*record, sizeof(struct contact_data[k+1]));
        data[0][0] = '\0';
        if(temp.first_name_posn){
            fseek(fptr, temp.first_name_posn, SEEK_SET);
            for(i = 0; (data[0][i] = fgetc(fptr)); i++);
            strcpy(record[k]->first_name, data[0]);
        }
        data[1][0] = '\0';
        if(temp.last_name_posn){
            fseek(fptr, temp.last_name_posn, SEEK_SET);
            for(i = 0; (data[1][i] = fgetc(fptr)); i++);
            strcpy(record[k]->last_name, data[1]);
        }
        data[2][0] = '\0';
        if(temp.company_name_posn){
            fseek(fptr, temp.company_name_posn, SEEK_SET);
            for(i = 0; (data[2][i] = fgetc(fptr)); i++);
            strcpy(record[k]->company_name, data[2]);
        }
        data[3][0] = '\0';
        record[k]->phone_number = temp.phone_number;
        if(temp.email_posn){
            fseek(fptr, temp.email_posn, SEEK_SET);
            for(i = 0; (data[3][i] = fgetc(fptr)); i++);
            strcpy(record[k]->email, data[3]);
        }
        k++;
        j = 0;
        fseek(fptr, temp.next, SEEK_SET);
        j = fread(&temp, sizeof(struct contact), 1, fptr);
    }while(j);
    fclose(fptr);
    return k;

}

