#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contactDefns.h"
int contactDetails(struct contact_data **record, int contact_number, int k){
    char action[10];
    char string[101];
    int i;
    unsigned int phone_number; 
    action[0] = '\0';

    printf("Contact #%d\n", contact_number + 1);
    if(record[contact_number]->first_name[0]){
        printf("First Name: %s\n",record[contact_number]->first_name);
    }else{
        printf("First Name: \n");
    }
    if(record[contact_number]->last_name[0]){
        printf("Last Name: %s\n",record[contact_number]->last_name);
    }else{
        printf("Last Name: \n");
    }
    if(record[contact_number]->company_name[0]){
        printf("Company Name: %s\n",record[contact_number]->company_name);
    }else{
        printf("Company Name: \n");
    }
    printf("Phone Number: %lu\n",record[contact_number]->phone_number);
    printf("Email: %s\n",record[contact_number]->email);
    printf("Action:");
    do{
        fgets(action,10,stdin);
        if(action[0] == 'E'){
            printf("Contact #%d\n", contact_number + 1);
            printf("First Name: %s\n",record[contact_number]->first_name);
            printf("Last Name: %s\n",record[contact_number]->last_name);
            printf("Company Name: %s\n",record[contact_number]->company_name);
            do{
                printf("Phone Number: ");
                fgets(string, 100, stdin);
                phone_number = strtoul(string,NULL, 10);
            }while(phone_number != 0 && (strlen(string) == 7 || strlen(string) == 10));
            do{
                i = 0;
                printf("Email: ");
                fgets(string, 100, stdin);
                i = sscanf(string,"%*s@%*s.%*c%*c%*c");
            }while( i > 0);
            printf("Action:");
            do{
                fgets(action,10,stdin);
                if(action[0] == 'S'){
                    record[contact_number]->phone_number = phone_number;
                    strcpy(record[contact_number]->email, string);
                    action[0] = 'R';
                }
            }while(action[0] != 'R' || action[0] != 'D');
        }
        if(action[0] == 'D'){
            for(i = contact_number; i < k; i++){
                record[i] = record[i+1];
            }
            *record = realloc(*record, sizeof(struct contact_data) * (long unsigned) k - 1);
            k--;
        }
    }while(action[0] != 'R');
    return 0;
}

