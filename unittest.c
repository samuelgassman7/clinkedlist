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
	struct e* prev;
	int x;
	struct e* next;
}ehead, eone, etwo, ethree;

struct f{
	struct f* prev;
	struct f* next;
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

	
	ghead.x=0, gone.x=1, gtwo.x=2, gthree.x=3;
	hhead.x=0, hone.x=1, htwo.x=2, hthree.x=3;
	ihead.x=0, ione.x=1, itwo.x=2, ithree.x=3;

	
	ghead.next=NULL; gone.next=NULL; gtwo.next=NULL; gthree.next=NULL;
	hhead.next=NULL; hone.next=NULL; htwo.next=NULL; hthree.next=NULL;
	ihead.next=NULL; ione.next=NULL; itwo.next=NULL; ithree.next=NULL;
	

	ghead.prev=NULL; gone.prev=NULL; gtwo.prev=NULL; gthree.prev=NULL;
	hhead.prev=NULL; hone.prev=NULL; htwo.prev=NULL; hthree.prev=NULL;
	ihead.prev=NULL; ione.prev=NULL; itwo.prev=NULL; ithree.prev=NULL;

	gtail = &ghead;
	htail = &hhead;
	itail = &ihead;


	unsigned int gnext = (unsigned int) __builtin_offsetof(struct g, next);
	unsigned int hnext = (unsigned int) __builtin_offsetof(struct h, next);
	unsigned int inext = (unsigned int) __builtin_offsetof(struct i, next);

	unsigned int gprev = (unsigned int) __builtin_offsetof(struct g, prev);
	unsigned int hprev = (unsigned int) __builtin_offsetof(struct h, prev);
	unsigned int iprev = (unsigned int) __builtin_offsetof(struct i, prev);



	jhead.x=0, jone.x=1, jtwo.x=2, jthree.x=3;
	khead.x=0, kone.x=1, ktwo.x=2, kthree.x=3;

	jhead.next=NULL; jone.next=NULL; jtwo.next=NULL; jthree.next=NULL;
	khead.next=NULL; kone.next=NULL; ktwo.next=NULL; kthree.next=NULL;

	unsigned int jnext = (unsigned int) __builtin_offsetof(struct j, next);
	unsigned int knext = (unsigned int) __builtin_offsetof(struct k, next);


	lhead.x=0, lone.x=1, ltwo.x=2, lthree.x=3;

	lhead.next=NULL; lone.next=NULL; ltwo.next=NULL; lthree.next=NULL;
	ltail = &lhead;

	unsigned int lnext = (unsigned int) __builtin_offsetof(struct l, next);



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


	addIterativelyWithPrev(&dhead, &done, dnext, dprev);
	addIterativelyWithPrev(&dhead, &dtwo, dnext, dprev);
	addIterativelyWithPrev(&dhead, &dthree, dnext, dprev);
	assert(dhead.next !=NULL);
	assert(dhead.next->x == 1);
	assert(dhead.next->next !=NULL);
	assert(dhead.next->next->x ==2);
	assert(dhead.next->next->next !=NULL);
	assert(dhead.next->next->next->x ==3);
	PRINTINTLIST(d, dhead, dtemp);


	addIterativelyWithPrev(&ehead, &eone, enext, eprev);
	addIterativelyWithPrev(&ehead, &etwo, enext, eprev);
	addIterativelyWithPrev(&ehead, &ethree, enext, eprev);
	assert(ehead.next !=NULL);
	assert(ehead.next->x == 1);
	assert(ehead.next->next !=NULL);
	assert(ehead.next->next->x ==2);
	assert(ehead.next->next->next !=NULL);
	assert(ehead.next->next->next->x ==3);
	PRINTINTLIST(e, ehead, etemp);


	addIterativelyWithPrev(&fhead, &fone, fnext, fprev);
	addIterativelyWithPrev(&fhead, &ftwo, fnext, fprev);
	addIterativelyWithPrev(&fhead, &fthree, fnext, fprev);
	assert(fhead.next !=NULL);
	assert(fhead.next->x == 1);
	assert(fhead.next->next !=NULL);
	assert(fhead.next->next->x ==2);
	assert(fhead.next->next->next !=NULL);
	assert(fhead.next->next->next->x ==3);
	PRINTINTLIST(f, fhead, ftemp);


	addToTailWithPrev((void*)&gtail, &gone, gnext, gprev);
	addToTailWithPrev((void*)&gtail, &gtwo, gnext, gprev);
	addToTailWithPrev((void*)&gtail, &gthree, gnext, gprev);
	assert(ghead.next !=NULL);
	assert(ghead.next->x == 1);
	assert(ghead.next->next !=NULL);
	assert(ghead.next->next->x ==2);
	assert(ghead.next->next->next !=NULL);
	assert(ghead.next->next->next->x ==3);
	PRINTINTLIST(g, ghead, gtemp);


	addToTailWithPrev((void*)&htail, &hone, hnext, hprev);
	addToTailWithPrev((void*)&htail, &htwo, hnext, hprev);
	addToTailWithPrev((void*)&htail, &hthree, hnext, hprev);
	assert(hhead.next !=NULL);
	assert(hhead.next->x == 1);
	assert(hhead.next->next !=NULL);
	assert(hhead.next->next->x ==2);
	assert(hhead.next->next->next !=NULL);
	assert(hhead.next->next->next->x ==3);
	PRINTINTLIST(h, hhead, htemp);


	addToTailWithPrev((void*)&itail, &ione, inext, iprev);
	addToTailWithPrev((void*)&itail, &itwo, inext, iprev);
	addToTailWithPrev((void*)&itail, &ithree, inext, iprev);
	assert(ihead.next !=NULL);
	assert(ihead.next->x == 1);
	assert(ihead.next->next !=NULL);
	assert(ihead.next->next->x ==2);
	assert(ihead.next->next->next !=NULL);
	assert(ihead.next->next->next->x ==3);
	PRINTINTLIST(i, ihead, itemp);


	addIteratively(&jhead, &jone, jnext);
	addIteratively(&jhead, &jtwo, jnext);
	addIteratively(&jhead, &jthree, jnext);
	assert(jhead.next !=NULL);
	assert(jhead.next->x == 1);
	assert(jhead.next->next !=NULL);
	assert(jhead.next->next->x ==2);
	assert(jhead.next->next->next !=NULL);
	assert(jhead.next->next->next->x ==3);
	PRINTINTLIST(j, jhead, jtemp);


	addIteratively(&khead, &kone, knext);
	addIteratively(&khead, &ktwo, knext);
	addIteratively(&khead, &kthree, knext);
	assert(khead.next !=NULL);
	assert(khead.next->x == 1);
	assert(khead.next->next !=NULL);
	assert(khead.next->next->x ==2);
	assert(khead.next->next->next !=NULL);
	assert(khead.next->next->next->x ==3);
	PRINTINTLIST(k, khead, ktemp);


	addToTail((void*) &ltail, &lone, lnext);
	addToTail((void*) &ltail, &ltwo, lnext);
	addToTail((void*) &ltail, &lthree, lnext);
	assert(lhead.next !=NULL);
	assert(lhead.next->x == 1);
	assert(lhead.next->next !=NULL);
	assert(lhead.next->next->x ==2);
	assert(lhead.next->next->next !=NULL);
	assert(lhead.next->next->next->x ==3);
	PRINTINTLIST(l, lhead, ltemp);




}
