CC=gcc
CFLAGS=-Wall -ansi -g3 -O0

all: contactList

contactList: contactList.o loadContacts.o displayContacts.o printList.o contactDetails.o addContact.o sortList.o saveContacts.o
	$(CC) -o contactList contactList.o loadContacts.o displayContacts.o printList.o contactDetails.o addContact.o sortList.o saveContacts.o

contactList.o: contactList.c contactDefns.h
	$(CC) $(CFLAGS) -c contactList.c

displayContacts.o: displayContacts.c printList.o contactDefns.h
	$(CC) $(CFLAGS) -c displayContacts.c

loadContacts.o: loadContacts.c contactDefns.h
	$(CC) $(CFLAGS) -c loadContacts.c

printList.o: printList.c contactDefns.h
	$(CC) $(CFLAGS) -c printList.c

contactDetails.o: contactDetails.c contactDefns.h
	$(CC) $(CFLAGS) -c contactDetails.c

addContact.o: addContact.c contactDefns.h
	$(CC) $(CFLAGS) -c addContact.c

sortList.o: sortList.c contactDefns.h
	$(CC) $(CFLAGS) -c sortList.c

saveContacts.o: saveContacts.c contactDefns.h
	$(CC) $(CFLAGS) -c saveContacts.c
clean:
	rm contactList contactList.o saveContacts.o sortList.o addContact.o displayContacts.o loadContacts.o printList.o contactDetails.o 
