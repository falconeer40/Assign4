#include <stdio.h>
#include <stdlib.h>
#include "contactDefns.h"
int main(){
    int k;
    struct contact_data *record;
    k = 0;
    record = malloc(sizeof(struct contact_data));
    k = loadContacts(k, &record);
/*        printf("\e[H\e[2J");*/
    k = displayContacts(k, &record);
    printf("2");
    saveContacts(&record, k);
    return 0;
}
