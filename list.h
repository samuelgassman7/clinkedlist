#ifndef listheader
#define listheader

#include <stdio.h>
#include <stdint.h>

int
addToTailWithPrev(void ** tail, void * add, unsigned int nextoffset, unsigned int prevoffset){
	int* tail2 = (int*) *tail;
	int *toadd = (int*) add;

	//tail.next
	int * next = tail2 + nextoffset/sizeof(int);
	printf("tail.next is: %p\n", (void*) next);	
	
	//next = toadd
	*(next) = (uintptr_t)toadd;
	
	//toadd.prev
	printf("address of toadd: %p\n", (void*) toadd);
	int * prev = toadd + prevoffset/sizeof(int);
	printf("toadd.prev is: %p\n", (void*) prev);

	//prev = tail
	*(prev) = (uintptr_t)tail2;
	
	//tail = toadd
	*tail = toadd;
}

int
addToTail(void ** tail, void * add, unsigned int nextoffset){
	int * tail2 = (int*) *(tail);
	int *toadd = (int*) add;
	
	//tail.next
	int * next = tail2 + nextoffset/sizeof(int);
	
	//next = toadd
	*(next) = (uintptr_t)toadd;
	
	//tail = toadd
	*tail = toadd;

}


int
addIterativelyWithPrev(void * head, void * add, unsigned int nextoffset, unsigned int prevoffset){
	int * toadd = (int *)add;
	head = (int *)head;

	int * iterator = head;	
	int * lastnode = NULL;
	int * prev = toadd + prevoffset/sizeof(int);
	
	//printf("address being dereferenced is: %p", (void*) (iterator + nextoffset));
	if(*(iterator+nextoffset/sizeof(int)) == (uintptr_t)NULL){
		
		iterator += nextoffset/sizeof(int);
		*(iterator) = (uintptr_t)toadd;
		*(prev) = (uintptr_t)head;
		//printf("address of lastnode should be address of head: %p\n", (void*) *(prev));
		//printf("in if: address of list1.next: %x\n", *(iterator));
		
		return 0;
	}


	iterator += nextoffset/sizeof(int);
	while(*iterator!=(uintptr_t)NULL){
		lastnode = iterator-nextoffset/sizeof(int);
		iterator = (int*)((uintptr_t)*(iterator));
		iterator +=nextoffset/sizeof(int);
	}

	//printf("address of lastnode should be address of toadd: %p\n", (void*)lastnode);
	//printf("address of iterator is: %p\n", (void*)iterator);
	*iterator = (uintptr_t)toadd;
	*(prev) =  (uintptr_t)(iterator- nextoffset/sizeof(int));
	

}

int
addIteratively(void * head, void * add, unsigned int nextoffset){
	int * toadd = (int *) add;
	head = (int *)head;

	int * iterator = head;	
	int * lastnode = NULL;
	
	//printf("address being dereferenced is: %p", (void*) (iterator + nextoffset));
	if(*(iterator+nextoffset/sizeof(int)) == (uintptr_t)NULL){
		
		iterator += nextoffset/sizeof(int);
		*(iterator) = (uintptr_t)toadd;
		//printf("in if: address of list1.next: %x\n", *(iterator));
		
		return 0;
	}


	iterator += nextoffset/sizeof(int);
	while(*iterator!=(uintptr_t)NULL){
		lastnode = iterator-nextoffset/sizeof(int);
		iterator = (int*)((uintptr_t)*(iterator));
		iterator +=nextoffset/sizeof(int);
	}

	//printf("address of lastnode should be address of toadd: %p\n", (void*)lastnode);
	//printf("address of iterator is: %p\n", (void*)iterator);
	*iterator = (uintptr_t)toadd;
	

}

void *
removeAtIndex(void * head, int idx, unsigned int nextoffset, unsigned int prevoffset){
	int * itereator = head;
	int * lastnode = NULL;
	if(head == NULL){
		return 0;
	}
	if(idx>0 && *(iterator + nextoffset/sizeof(int)) == (uintptr_t)NULL){
		return 0;
	}
	int count = 0;
	iterator += nextoffset/sizeof(int);
	while(*iterator!=(uintptr_t)NULL && count != idx){
		lastnode = iterator-nextoffset/sizeof(int);
		iterator = (int*)((uintptr_t)*(iterator));
		iterator +=nextoffset/sizeof(int);
	}
	if(count != idx){
		return 0;
	}

	//previousnode.next = nextnode.next;
	lastnode+=nextoffset/sizeof(int);
	*(lastnode) = *(iterator);
	
	if(*(iterator) != (uintptr_t)NULL){
		iterator= *(iterator + prevoffset/sizeof(int));
		lastnode-= nextoffset/sizeof(int);
		lastnode+= 

	


}

#endif
