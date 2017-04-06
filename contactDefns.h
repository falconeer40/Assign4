#include <stdio.h>
struct contact{
    unsigned long phone_number;
    long first_name_posn;
    long last_name_posn;
    long company_name_posn;
    long email_posn;
    long next;
};

struct contact_data{
    unsigned long phone_number;
    char first_name[101];
    char last_name[101];
    char company_name[101];
    char email[101];
} contact_data;

extern int loadContacts(int k, struct contact_data **record);

extern int sortList(const void *j, const void *k);

extern int displayContacts(int k, struct contact_data **record);

extern void printList(struct contact_data *record, int start, int end);

extern int contactDetails (struct contact_data **record, int contact_number, int k);

extern int addContact(struct contact_data **record, int k);

extern void saveContacts(struct contact_data **record, int k);

