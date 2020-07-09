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
	struct list2 * next;
	char * str;
	struct list2 * prev;
}head, one, two, three;

int
main(){
	list1.val = 1;
	list1.next = NULL;
	list1.prev = NULL;

	toadd.val = 2;
	toadd.next = NULL;
	toadd.prev = NULL;

	third.val = 3;
	third.next = NULL;
	third.prev = NULL;

	
	fourth.val = 4;
	fourth.next = NULL;
	fourth.prev = NULL;


	struct listtest * fifth = malloc(sizeof(struct listtest));
	fifth->val = 5;
	fifth->next = NULL;
	fifth->prev = NULL;
	//printf("third addresses\nthird.val: %x\nthird.next: %x\nthird.prev: %x\n", &third.val, &third.next, &third.prev);

	//printf("toadd.next is: %x\n", toadd.next); 

	/*
	printf("head: %p\n", (void*)&list1);
	printf("head.next: %p\n", (void*) &list1.next);
	printf("head.prev: %p\n\n", (void*) &list1.prev);
	printf("toadd: %p\n", (void*)&toadd);
	printf("toadd.next: %p\n", (void*) &toadd.next);
	printf("toadd.prev: %p\n\n", (void*) &toadd.prev);
	printf("third: %p\n", (void*)&third);
	printf("third.next: %p\n", (void*)&third.next);
	printf("third.prev: %p\n\n", (void*)&third.prev);
	printf("fourth: %p\n", (void*)&fourth);
	printf("fourth.next: %p\n", (void*)&fourth.next);
	printf("fourth.prev: %p\n\n", (void*)&fourth.prev);	
	printf("fifth: %p\n", (void*)fifth);
	printf("fifth.next: %p\n", (void*)&(fifth->next));
	printf("fifth.prev: %p\n\n", (void*)&(fifth->prev));
	*/
	//printf("head + nextoffset Original: %p\n", &(list1.next));	
	

	uintptr_t val = (uintptr_t)&list1;
	uintptr_t next = (uintptr_t)&list1.next;
	uintptr_t prev = (uintptr_t)&list1.prev;

	//printf("the difference between the next and val is: %d; prev and val: %d", (uintptr_t)next - (uintptr_t)val, (uintptr_t)prev - (uintptr_t)val);
	addIterativelyWithPrev((void*) &list1, (void*) &toadd, (uintptr_t)next - (uintptr_t)val, (uintptr_t)prev - (uintptr_t)val);

	//printf("the address of list1.next is: %p\n", &list1.next);
	//printf("the value of list1.next is: %d\n", list1.next);
	//printf("the address of toadd is: %p\n", &toadd);
	//printf("Second node info:\n");

	addIterativelyWithPrev((void*) &list1, (void*) &third, sizeof(third.next), sizeof(third.next) + sizeof(third.prev));
	addIterativelyWithPrev((void*) &list1, (void*) &fourth, sizeof(fourth.next), sizeof(fourth.next) + sizeof(fourth.prev));
	addIterativelyWithPrev((void*) &list1, (void*) fifth, sizeof(fourth.next), sizeof(fourth.next) + sizeof(fourth.prev));

	struct listtest * temp = &list1;
	puts("print forwards:\n");
	while(temp!= NULL){
		printf("%d\n", temp->val);
		temp = temp->next;
	}
	
	puts("print backwards:\n");
	temp = fifth;
	while(temp != NULL){
		printf("%d\n", temp->val);
		temp = temp->prev;
	}

	//printf("ADDRESS OF 0th ELEMENT IS: %x\n", (void*)&list1);
	//printf("ADDRESS OF 0th ELEMENT.NEXT IS: %x\n", (void*)&list1.next);
	//printf("VALUE OF 0th ELEMENT.NEXT IS: %x\n\n", (void*)list1.next);
	//printf("ADDRESS OF 1st ELEMENT IS: %x\n", (void*)&toadd);
	//printf("ADDRESS OF 2nd ELEMENT IS: %x\n", (void*)&third);
	void* realhead = &list1;
	struct listtest * returned = (struct listtest*)removeAtIndex((void*) &realhead, 1, sizeof(fourth.next), sizeof(fourth.next) + sizeof(fourth.prev));
	temp = (struct listtest *)realhead;
	//printf("first element is: %x", (void*) temp);
	puts("print forwards post removal:\n");
	while(temp!= NULL){
		printf("%d\n", temp->val);
		temp = temp->next;
	}
			

	puts("print backwards post removal:\n");
	temp = fifth;
	while(temp != NULL){
		printf("%d\n", temp->val);
		temp = temp->prev;
	}


	//printf("RETURNED ADDRESS %p\n", (void*)returned);


	free(fifth);




	
	head.str = malloc(5);
	strcpy(head.str, "head\0");
	head.next = NULL;
	head.prev = NULL;
	

	one.str = malloc(4);
	strcpy(one.str, "one\0");
	one.next = NULL;
	one.prev = NULL;

	
	two.str = malloc(4);
	strcpy(two.str, "two\0");
	two.next = NULL;
	two.prev = NULL;

	three.str = malloc(6);
	strcpy(three.str, "three\0");
	three.next = NULL;
	three.prev = NULL;

	uintptr_t str = (uintptr_t)&head;
	next = (uintptr_t)&head.next;
	prev = (uintptr_t)&head.prev;

	addIterativelyWithPrev((void*) &head, (void*) &one, (uintptr_t)next - (uintptr_t)str, (uintptr_t)prev - (uintptr_t)str);

	addIterativelyWithPrev((void*) &head, (void*) &two, (uintptr_t)next - (uintptr_t)str, (uintptr_t)prev - (uintptr_t)str);
	addIterativelyWithPrev((void*) &head, (void*) &three, (uintptr_t)next - (uintptr_t)str, (uintptr_t)prev - (uintptr_t)str);

	puts("print forwards:\n");
	struct list2 * temp2 = &head;
	while(temp2!= NULL){
		printf("%s\n", temp2->str);
		temp2 = temp2->next;
	}

	puts("print backwards:\n");
	temp2 = &three;
	while(temp2 != NULL){
		printf("%s\n", temp2->str);
		temp2 = temp2->prev;
	}

	free(head.str);
	free(one.str);
	free(two.str);
	free(three.str);



}
