#include <stdio.h>
#include <ctype.h>
#include "contactDefns.h"

void printList(struct contact_data *record, int start, int end){
    char state;
    int i;
    int j;

    i = 0;
    i = end - start;
    if( i > 5){
        i = 5;
    }
    printf("Number of Contacts = %d\n", end);
    if(end > 0){
        if( i >= 0){
            if(record[start].last_name[0]){
                state = toupper(record[start].last_name[0]);
            } else {
                state = toupper(record[start].company_name[0]);
            }
            printf("%c\n",state);
            for(j = 0; j < i; j++){
                if(record[start + j].last_name[0]){
                    if(toupper(record[start + j].last_name[0]) != state){
                        state = toupper(record[start + j].last_name[0]);
                        printf("%c\n",state);
                    }
                    printf("\t%d. %s\n",j + start + 1,record[start + j].last_name);
                } else {
                    if(toupper(record[start + j].company_name[0]) != state){
                        state = toupper(record[start + j].company_name[0]);
                        printf("%c\n",state);
                    }
                    printf("\t%d. %s\n",j + start + 1,record[start + j].company_name);
                }
            }
        }
    }
    return;
}
