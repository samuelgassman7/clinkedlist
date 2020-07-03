#include <stdio.h>
#include "list.h"

struct listtest{
	int val;
	struct listtest * next;
	struct listtest * prev;
}list1, toadd, third, fourth;


int
main(){
	list1.val = 10;
	list1.next = NULL;
	list1.prev = NULL;

	toadd.val = 7;
	toadd.next = NULL;
	toadd.prev = NULL;

	third.val = 8;
	third.next = NULL;
	third.prev = NULL;

	
	fourth.val = 4;
	fourth.next = NULL;
	fourth.prev = NULL;

	//printf("third addresses\nthird.val: %x\nthird.next: %x\nthird.prev: %x\n", &third.val, &third.next, &third.prev);

	//printf("toadd.next is: %x\n", toadd.next); 


	printf("head: %p\n", (void*)&list1);
	printf("head.next: %p\n", (void*) &list1.next);
	printf("toadd: %p\n", (void*)&toadd);
	printf("toadd.next: %p\n", (void*) &toadd.next);
	//printf("third: %p\n", (void*)&third);
	//printf("head + nextoffset Original: %p\n", &(list1.next));	
	addIteratively((void *)&list1, (void *)&toadd, sizeof(toadd.next), sizeof(toadd.next) + sizeof(toadd.prev));

	//printf("the address of list1.next is: %p\n", &list1.next);
	//printf("the value of list1.next is: %d\n", list1.next);
	//printf("the address of toadd is: %p\n", &toadd);
	printf("Second node info:\n");

	addIteratively2((void*) &list1, (void*) &third, sizeof(third.next), sizeof(third.next) + sizeof(third.prev));
	addIteratively2((void*) &list1, (void*) &fourth, sizeof(fourth.next), sizeof(fourth.next) + sizeof(fourth.prev));

	struct listtest * temp = &list1;
	while(temp!= NULL){
		printf("%d\n", temp->val);
		temp = temp->next;
	}
	

}
