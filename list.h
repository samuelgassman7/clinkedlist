#ifndef listheader
#define listheader

#include <stdio.h>


int
addToTail(void * tail, void * toadd, void **next, void **prev){

}

int
addIteratively(void * head, int * toadd, int nextoffset, int prevoffset){

	head = (int *)head;
	toadd = (int *) toadd;

	int* iterator = head;	
	int * lastnode = NULL;

	
	printf("address being dereferenced is: %p", (void*) (iterator + nextoffset));
	if(*(iterator+nextoffset/sizeof(int)) == NULL){
		
		iterator += nextoffset/sizeof(int);
		*(iterator) = toadd;
		
		printf("in if: address of list1.next: %x\n", *(iterator));
		
		return 0;
	}


	iterator += nextoffset/sizeof(int);
	while(*iterator!=NULL){
		lastnode = iterator-nextoffset/sizeof(int);
		iterator = *(iterator);
		iterator +=nextoffset/sizeof(int);
	}

	printf("address of lastnode should be address of toadd: %p\n", (void*)lastnode);
	printf("address of iterator is: %p\n", (void*)iterator);
	*iterator = toadd;
	

}

int 
removeAtIndex(void * head, int idx){

}

#endif
