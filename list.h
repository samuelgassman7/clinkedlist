#ifndef listheader
#define listheader

#include <stdio.h>
#include <stdint.h>

int
addToTail(void * tail, void * toadd, void **next, void **prev){

}

int
addIteratively(void * head, int * toadd, unsigned int nextoffset, unsigned int prevoffset){

	head = (int *)head;
	toadd = (int *) toadd;

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
removeAtIndex(void * head, int idx){

}

#endif
