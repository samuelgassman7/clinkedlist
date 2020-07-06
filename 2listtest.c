#include <stdio.h>
#include <string.h>
#include <stdint.h>


#include "list.h"

struct mylist{
	char arr[5];
	int x;
	int y;
	struct mylist * next;
	struct mylist * prev;
}head, *tail, one, two;


int 
main(){
	tail = &head;

	strcpy(head.arr, "abcd\0");
	head.x = 1;
	head.y = 2;
	head.next = NULL;
	head.prev = NULL;

	strcpy(one.arr, "efgh\0");
	one.x = 3;
	one.y = 4;
	one.next = NULL;
	one.prev = NULL;

	strcpy(two.arr, "ijkl\0");
	two.x = 5;
	two.y = 6;
	two.next = NULL;
	two.prev = NULL;

	int * base = (int*)&head;
	int * next = (int*)&head.next;
	int * prev = (int*)&head.prev;
	
	unsigned int nextoff = (uintptr_t)next - (uintptr_t)base;
	unsigned int prevoff = (uintptr_t)prev - (uintptr_t)base;
	printf("tail.next is: %p\n", (void*) &(tail->next));
	printf("toadd.prev is: %p\n", (void*) &one.prev);
	addToTailWithPrev((void**)&tail, (void*)&one, nextoff, prevoff);
	addToTailWithPrev((void**)&tail, (void*)&two, nextoff, prevoff);

	//addIterativelyWithPrev((void*)&head, (void*)&one, nextoff, prevoff);
	//addIterativelyWithPrev((void*)&head, (void*)&two, nextoff, prevoff);

	struct mylist * temp = &head;
	while(temp != NULL){
		printf("%s, %d, %d\n", temp->arr, temp->x, temp->y);
		temp = temp->next;
	}
}
