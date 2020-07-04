#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "list.h"

struct listtest{
	int val;
	struct listtest * next;
	struct listtest * prev;
}list1, toadd, third, fourth;


struct list2{
	char * str;
	struct list2 * next;
	struct list2 * prev;
}head, one, two, three;

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


	struct listtest * fifth = malloc(sizeof(struct listtest));
	fifth->val = 9;
	fifth->next = NULL;
	fifth->prev = NULL;
	//printf("third addresses\nthird.val: %x\nthird.next: %x\nthird.prev: %x\n", &third.val, &third.next, &third.prev);

	//printf("toadd.next is: %x\n", toadd.next); 


	printf("head: %p\n", (void*)&list1);
	printf("head.next: %p\n", (void*) &list1.next);
	printf("toadd: %p\n", (void*)&toadd);
	printf("toadd.next: %p\n", (void*) &toadd.next);
	//printf("third: %p\n", (void*)&third);
	//printf("head + nextoffset Original: %p\n", &(list1.next));	
	

	int * val = &list1.val;
	int * next = (int*)&list1.next;
	int * prev = (int*)&list1.prev;

	printf("the difference between the next and val is: %d; prev and val: %d", (uintptr_t)next - (uintptr_t)val, (uintptr_t)prev - (uintptr_t)val);
	//addIteratively((void *)&list1, (void *)&toadd, sizeof);

	printf("the address of list1.next is: %p\n", &list1.next);
	printf("the value of list1.next is: %d\n", list1.next);
	printf("the address of toadd is: %p\n", &toadd);
	//printf("Second node info:\n");

	addIteratively((void*) &list1, (void*) &third, sizeof(third.next), sizeof(third.next) + sizeof(third.prev));
	addIteratively((void*) &list1, (void*) &fourth, sizeof(fourth.next), sizeof(fourth.next) + sizeof(fourth.prev));
	addIteratively((void*) &list1, (void*) fifth, sizeof(fourth.next), sizeof(fourth.next) + sizeof(fourth.prev));

	struct listtest * temp = &list1;
	while(temp!= NULL){
		printf("%d\n", temp->val);
		temp = temp->next;
	}
	
	free(fifth);




	
	head.str = malloc(5);
	strcpy(head.str, "head\0");
	head.next = NULL;
	head.prev = NULL;
	

	one.str = malloc(4);
	strcpy(one.str, "one\0");
	one.next = NULL;
	one.prev = NULL;

	
	int * str = (int*)&head.str;
	next = (int*)&head.next;
	prev = (int*)&head.prev;

	addIteratively((void*) &head, (void*) &one, (uintptr_t)next - (uintptr_t)str, (uintptr_t)prev - (uintptr_t)str);



	struct list2 * temp2 = &head;
	while(temp2!= NULL){
		printf("%s\n", temp2->str);
		temp2 = temp2->next;
	}

}
