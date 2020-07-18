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
	//printf("tail.next is: %p\n", (void*) next);	
	
	//next = toadd
	*(next) = (uintptr_t)toadd;
	
	//toadd.prev
	//printf("address of toadd: %p\n", (void*) toadd);
	int * prev = toadd + prevoffset/sizeof(int);
	//printf("toadd.prev is: %p\n", (void*) prev);

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


//optional tail parameter
void *
removeAtIndex(void ** head, void ** tail, int idx, unsigned int nextoffset, unsigned int prevoffset){
	int * iterator = (int*)*head;
	int * lastnode = NULL;
	int * toreturn = NULL;
	//empty list
	if(*head == NULL){
		puts("SO THAT'S IT? NO HEAD?\n");
		fflush(stdout);
		return 0;
	}
	
	//remove 0th element from list with a size of at least 2
	if(idx == 0 && *(iterator + nextoffset/sizeof(int)) != (uintptr_t)NULL){
		toreturn = (int*)*head;
		//iterator = iterator.next
		iterator = (int*)((uintptr_t)*(iterator+nextoffset/sizeof(int)));

		//iterator.prev = NULL
		iterator += prevoffset/sizeof(int);
		*(iterator)= (uintptr_t) NULL;
		//head = next
		iterator -=prevoffset/sizeof(int);
		
		*head = iterator;
		return toreturn;
		
	}

	//remove 0th element from list with a size of 1
	else if(idx == 0 && *(iterator + nextoffset/sizeof(int)) == (uintptr_t)NULL){
		toreturn = *head;
		*head = NULL;
		return toreturn;
	}

	//remove NON 0th element from list with a size of 1
	else if(idx>0 && *(iterator + nextoffset/sizeof(int)) == (uintptr_t)NULL){
		puts("INDEX OUT OF RANGE. ONLY HEAD ELEMENT PRESENT\n");
		fflush(stdout);
		return 0;
	}

	//find nth element
	int count = 0;
	iterator += nextoffset/sizeof(int);
	while(*iterator!=(uintptr_t)NULL && count != idx){
		lastnode = iterator-nextoffset/sizeof(int);
		iterator = (int*)((uintptr_t)*(iterator));
		iterator +=nextoffset/sizeof(int);
		count++;
	}

	//either the index was in the list, or it wasnt. If it wasnt:
	if(count != idx){
		puts("INDEX OUT OF RANGE\n");
		fflush(stdout);
		return 0;
	}

	//check if the element to remove is at the end of the list
	//Requirements:
	//	count == idx and iterator.next == NULL (aka last element of the list)
	if(count == idx && *iterator == (uintptr_t)NULL && tail != NULL && *tail != NULL){
		*tail = lastnode;
	}



	//else, the index is inside the bounds of the list, adjust the pointers:

	//previousnode.next = thisnode.next;
	lastnode+=nextoffset/sizeof(int);
	*(lastnode) = *(iterator);
	iterator -=nextoffset/sizeof(int);	

	toreturn = iterator;
	

	//(aka are we removing the last element or not. If we are, just do the above.
	//If we are not, we gotta adjust the "prev" pointer of the node after it.)
	//
	//
	//if thisnode.next != NULL:
	//	nextnode.prev = prev
	iterator +=nextoffset/sizeof(int);
	if(*(iterator) != (uintptr_t)NULL){
		iterator = (int*)((uintptr_t)*(iterator));
		//iterator-=nextoffset/sizeof(int);
		iterator += prevoffset/sizeof(int);
		lastnode-= nextoffset/sizeof(int);
		*(iterator) = (uintptr_t)lastnode;
	}
	//no else required, if thisnode.next == NULL where thisnode is to be removed, then
	//no other "prev" pointers need to be adjusted.

	return toreturn;

}

#endif
