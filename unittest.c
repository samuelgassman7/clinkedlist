#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include "list.h"
///////////////////////////////
//single integer doubly linked lists
//with various internal structures,
//total of 4 elements for each, no tail.


struct a{
	int x;
	struct a* next;
	struct a* prev;
}ahead, aone, atwo, athree;

struct b{
	struct b* next;
	int x;
	struct b* prev;
}bhead, bone, btwo, bthree;

struct c{
	struct c* next;
	struct c* prev;
	int x;
}chead, cone, ctwo, cthree;

struct d{
	int x;
	struct d* prev;
	struct d* next;
}dhead, done, dtwo, dthree;

struct e{
	struct d* prev;
	int x;
	struct d* next;
}ehead, eone, etwo, ethree;

struct f{
	struct d* prev;
	struct d* next;
	int x;
}fhead, fone, ftwo, fthree;




//////////////////////////////
//single integer doubly linked lists
//with various internal structures,
//total of 4 elements for each,
//possesses a tail.



struct g{
	int x;
	struct g* next;
	struct g* prev;
}ghead, gone, gtwo, gthree;
struct g* gtail;

struct h{
	struct h* next;
	int x;
	struct h* prev;
}hhead, hone, htwo, hthree;
struct h* htail;

struct i{
	struct i* next;
	struct i* prev;
	int x;
}ihead, ione, itwo, ithree;
struct i* itail;

///////////////////////////////
//single integer singly linked lists
//with various internal structures,
//total of 4 elements each, no tail.

struct j{
	int x;
	struct j* next;
}jhead, jone, jtwo, jthree;

struct k{
	struct k* next;
	int x;
}khead, kone, ktwo, kthree;



///////////////////////////////
//single integer singly linked list
//total 4 elements, posesses a tail.


struct l{
	struct l* next;
	int x;
}lhead, lone, ltwo, lthree;
struct l* ltail;


#define PRINTINTLIST(type, head, temp)\
	struct type * temp = &head;\
	while(temp!=NULL){\
		printf("%d\n", temp->x);\
		temp = temp->next;\
	}


int
main(){
	//standard output:
	//printf("Normal Text\n");
	//
	//standard error/guaranteed fail test:
	//assert(0);
	
	ahead.x=0, aone.x=1, atwo.x=2, athree.x=3;
	bhead.x=0, bone.x=1, btwo.x=2, bthree.x=3;
	chead.x=0, cone.x=1, ctwo.x=2, cthree.x=3;
	dhead.x=0, done.x=1, dtwo.x=2, dthree.x=3;
	ehead.x=0, eone.x=1, etwo.x=2, ethree.x=3;
	fhead.x=0, fone.x=1, ftwo.x=2, fthree.x=3;

	ahead.next=NULL; aone.next=NULL; atwo.next=NULL; athree.next=NULL;
	bhead.next=NULL; bone.next=NULL; btwo.next=NULL; bthree.next=NULL;
	chead.next=NULL; cone.next=NULL; ctwo.next=NULL; cthree.next=NULL;
	dhead.next=NULL; done.next=NULL; dtwo.next=NULL; dthree.next=NULL;
	ehead.next=NULL; eone.next=NULL; etwo.next=NULL; ethree.next=NULL;
	fhead.next=NULL; fone.next=NULL; ftwo.next=NULL; fthree.next=NULL;
		
	ahead.prev=NULL; aone.prev=NULL; atwo.prev=NULL; athree.prev=NULL;
	bhead.prev=NULL; bone.prev=NULL; btwo.prev=NULL; bthree.prev=NULL;
	chead.prev=NULL; cone.prev=NULL; ctwo.prev=NULL; cthree.prev=NULL;
	dhead.prev=NULL; done.prev=NULL; dtwo.prev=NULL; dthree.prev=NULL;
	ehead.prev=NULL; eone.prev=NULL; etwo.prev=NULL; ethree.prev=NULL;
	fhead.prev=NULL; fone.prev=NULL; ftwo.prev=NULL; fthree.prev=NULL;
	

	unsigned int anext = (unsigned int) __builtin_offsetof(struct a, next);
	unsigned int bnext = (unsigned int) __builtin_offsetof(struct b, next);
	unsigned int cnext = (unsigned int) __builtin_offsetof(struct c, next);
	unsigned int dnext = (unsigned int) __builtin_offsetof(struct d, next);
	unsigned int enext = (unsigned int) __builtin_offsetof(struct e, next);
	unsigned int fnext = (unsigned int) __builtin_offsetof(struct f, next);
	//printf("%d\n", anext);

	unsigned int aprev = (unsigned int) __builtin_offsetof(struct a, prev);
	unsigned int bprev = (unsigned int) __builtin_offsetof(struct b, prev);
	unsigned int cprev = (unsigned int) __builtin_offsetof(struct c, prev);
	unsigned int dprev = (unsigned int) __builtin_offsetof(struct d, prev);
	unsigned int eprev = (unsigned int) __builtin_offsetof(struct e, prev);
	unsigned int fprev = (unsigned int) __builtin_offsetof(struct f, prev);

	
///////////////////////////////////////////
//beginning of testing:


	addIterativelyWithPrev(&ahead, &aone, anext, aprev);
	addIterativelyWithPrev(&ahead, &atwo, anext, aprev);
	addIterativelyWithPrev(&ahead, &athree, anext, aprev);
	assert(ahead.next !=NULL);
	assert(ahead.next->x == 1);
	assert(ahead.next->next !=NULL);
	assert(ahead.next->next->x ==2);
	assert(ahead.next->next->next !=NULL);
	assert(ahead.next->next->next->x ==3);
	PRINTINTLIST(a, ahead, atemp);


	addIterativelyWithPrev(&bhead, &bone, bnext, bprev);
	addIterativelyWithPrev(&bhead, &btwo, bnext, bprev);
	addIterativelyWithPrev(&bhead, &bthree, bnext, bprev);
	assert(bhead.next !=NULL);
	assert(bhead.next->x == 1);
	assert(bhead.next->next !=NULL);
	assert(bhead.next->next->x ==2);
	assert(bhead.next->next->next !=NULL);
	assert(bhead.next->next->next->x ==3);
	PRINTINTLIST(b, bhead, btemp);


	addIterativelyWithPrev(&chead, &cone, cnext, cprev);
	addIterativelyWithPrev(&chead, &ctwo, cnext, cprev);
	addIterativelyWithPrev(&chead, &cthree, cnext, cprev);
	assert(chead.next !=NULL);
	assert(chead.next->x == 1);
	assert(chead.next->next !=NULL);
	assert(chead.next->next->x ==2);
	assert(chead.next->next->next !=NULL);
	assert(chead.next->next->next->x ==3);
	PRINTINTLIST(c, chead, ctemp);




}
