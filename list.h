#ifndef listheader
#define listheader

#include <stdio.h>
struct iterator{
	int * lastnode;
	int * next;
	int * prev;
};

int
addToTail(void * tail, void * toadd, void **next, void **prev){

}

int
addIteratively(void * head, int * toadd, int nextoffset, int prevoffset){

	head = (int *)head;
	toadd = (int *) toadd;

	struct iterator it;
	
//	puts("hi2\n");

	it.lastnode = NULL;
	it.next = head+nextoffset;
	it.prev = head+prevoffset;


	/*while((*(it.next))!=NULL){
		printf("%x\n", *it.next);
		fflush(stdout);
		it.next = *(it.next);
		/*
		puts("hi");
		printf("lastnode is: %p\n", (void*) it.next);
		printf("it.next test: %p\n", (void *) ((*it.next) + nextoffset));
		
		fflush(stdout);
		it.lastnode =(int *) (it.next);
		it.next = (int *) *(it.next) + nextoffset;
		*/
		//printf("lastnode is: %p\n", (void*)it.lastnode);
		//printf("it.next is: %p\n",(void*) it.next);
		//it.prev = (int *) *(it.prev) + prevoffset;
	//}

	puts("hi4\n");
	fflush(stdout);
	if(it.lastnode == NULL){
		//printf("address of head.next: %x\n", it.next);
	//	puts("hi3\n");
		//printf("value of head.next: %x\n", *(it.next));
		fflush(stdout);
		int * temp = it.next;
		*temp = toadd;
		//printf("in if: value of it.next is: %x\n", it.next);
		//printf("in if: address of toadd is: %x\n", toadd);
		//printf("in if: address of list1.next: %x\n", temp);
		//printf("in if: value of list1.next: %x\n", *temp);
		
		//puts("was null");
		return 0;
	}
	//char * temp = it.lastnode + nextoffset;
	//printf("it.next value is: %x\n", it.next);
	//*temp = toadd;
	//temp = toadd + prevoffset;
	//*temp= *(it.lastnode);
//	puts("hi5\n");


}


int
addIteratively2(void * head, int * toadd, int nextoffset, int prevoffset){

	head = (int *)head;
	toadd = (int *) toadd;

	
	
//	puts("hi2\n");
	int * lastnode = NULL;
	int * iterator = head; //head.next
	printf("address of head is: %p\n", (void*)iterator);
	iterator+=nextoffset/sizeof(int);
	printf("address of head's next: %p\n", (void*)iterator);
	iterator = *iterator;
	printf("address of toaddd according to iterator: %p\n", (void*)iterator);
	iterator+=nextoffset/sizeof(int);
	printf("address of toadd's next according to iterator: %p\n", (void*)iterator);

	while(*iterator!=NULL){
		lastnode = iterator-nextoffset/sizeof(int);
		iterator = *(iterator);
		iterator +=nextoffset/sizeof(int);
	}

	printf("address of lastnode should be address of toadd: %p\n", (void*)lastnode);
	printf("address of iterator is: %p\n", (void*)iterator);
	*iterator = toadd;
	//should be good to say *iterator = toadd; probably don't need lastnode actually


	/*while((*(it.next))!=NULL){
		printf("%x\n", *it.next);
		fflush(stdout);
		it.next = *(it.next);
		/*
		puts("hi");
		printf("lastnode is: %p\n", (void*) it.next);
		printf("it.next test: %p\n", (void *) ((*it.next) + nextoffset));
		
		fflush(stdout);
		it.lastnode =(int *) (it.next);
		it.next = (int *) *(it.next) + nextoffset;
		*/
		//printf("lastnode is: %p\n", (void*)it.lastnode);
		//printf("it.next is: %p\n",(void*) it.next);
		//it.prev = (int *) *(it.prev) + prevoffset;
	//}

	/*puts("hi4\n");
	fflush(stdout);
	if(it.lastnode == NULL){
		//printf("address of head.next: %x\n", it.next);
	//	puts("hi3\n");
		//printf("value of head.next: %x\n", *(it.next));
		fflush(stdout);
		int * temp = it.next;
		*temp = toadd;
		//printf("in if: value of it.next is: %x\n", it.next);
		//printf("in if: address of toadd is: %x\n", toadd);
		//printf("in if: address of list1.next: %x\n", temp);
		//printf("in if: value of list1.next: %x\n", *temp);
		
		//puts("was null");
		return 0;
	}
	//char * temp = it.lastnode + nextoffset;
	//printf("it.next value is: %x\n", it.next);
	//*temp = toadd;
	//temp = toadd + prevoffset;
	//*temp= *(it.lastnode);
//	puts("hi5\n");

	*/
}

int 
removeAtIndex(void * head, int idx){

}

#endif
