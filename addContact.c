#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contactDefns.h"

int addContact(struct contact_data **record, int k){
    char data[5][101];
    char action[10];
    unsigned long phone_number;
    char temp[50];
    int i;

    action[0] = '\0';

    for(i = 0; i < 5; i++){
        data[i][0] = '\0';
    }


    printf("First Name: ");
    fgets(data[0], 100, stdin);
    printf("Last Name: ");
    fgets(data[1], 100, stdin);
    if(strlen(data[1]) <= 1){
        do{
            printf("Company Name: ");
            fgets(data[2],100,stdin);
        }while(strlen(data[2]) <= 1);
    }else{
        printf("Company Name: ");
        fgets(data[2],100,stdin);
    }
    do{
       printf("Phone Number: ");
       fgets(data[3], 100, stdin);
       phone_number = strtoul(data[3],NULL, 10);
    }while(phone_number == 0 && (strlen(data[3]) != 7 || strlen(data[3]) != 10));
    do{
       printf("Email: ");
       fgets(data[4], 100, stdin);
    }while((sscanf(data[4],"%[^@]@%s",temp,temp) != 2 )|| (data[4][strlen(data[4]) - 5] != '.'));

    for(i = 0; i < 5; i++){
        if(strlen(data[i]) > 1){
            data[i][strlen(data[i]) - 1] = '\0';
        }
    }

    do{
        action[0] = '\0';
        printf("Action:");
        fgets(action,10,stdin);
        if(action[0] == 'S'){
            *record = realloc(*record, sizeof(struct contact_data[k+1]));
            
            memset(*record + k, 0, sizeof(**record));
            strcpy((*record)[k].first_name, data[0]);
            strcpy((*record)[k].last_name, data[1]);
            strcpy((*record)[k].company_name, data[2]);
            (*record)[k].phone_number = phone_number;
            strcpy((*record)[k].email, data[4]);
            action[0] = 'R';
            k++;
            if(k > 1){
                qsort(*record, k, sizeof(struct contact_data), sortList);
            }
         }
    }while(action[0] != 'R');
    return k;
}

