#include <string.h>
#include "contactDefns.h"
int sortList(const void *j, const void *k)
{
    int i;
    if((* (struct contact_data *)j).last_name && (* (struct contact_data *)k).last_name){
        i = strcmp((* (struct contact_data *)j).last_name, (* (struct contact_data *)k).last_name);
    }else if(!(* (struct contact_data *)j).last_name && !(* (struct contact_data *)k).last_name){
        i = strcmp((* (struct contact_data *)j).company_name, (* (struct contact_data *)k).company_name);
    }else if(!(* (struct contact_data *)j).last_name){
        i = strcmp((* (struct contact_data *)j).company_name, (* (struct contact_data *)k).last_name);
    }else{
        i = strcmp((* (struct contact_data *)j).last_name, (* (struct contact_data *)k).company_name);
    }
    return i;
}

