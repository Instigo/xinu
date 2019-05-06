/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

sid32 aArrived;
sid32 bArrived;
sid32 semaphore;

void a2();
void b2();


int main(int argc, char **argv)
{
	uint32 retval;
	aArrived = semcreate(0);
        bArrived = semcreate(0);   

		resume(create(b2, 1024, 20, "b1", 0));
        sleep(1);
        resume(create(a2, 1024, 30, "a1", 0));
        sleep(1);
	return OK;
}

/*void a1(){
    kprintf(" A1  ");
	//kprintf("a1() -> aArrived: %d, bArrived: %d\n", semcount(aArrived), semcount(bArrived));
    signal(aArrived);
    wait(bArrived);
	//kprintf("a1() -> aArrived: %d, bArrived: %d\n", semcount(aArrived), semcount(bArrived));
    kprintf(" A2 ");
}

void b1(){
    kprintf(" B1 ");
	//kprintf("b1() -> aArrived: %d, bArrived: %d\n", semcount(aArrived), semcount(bArrived));
    signal(bArrived);
    wait(aArrived);
	//kprintf("b1() -> aArrived: %d, bArrived: %d\n", semcount(aArrived), semcount(bArrived));
    kprintf(" B2 ");
}*/

void a2(){
    kprintf(" A1  ");
	//kprintf("a1() -> aArrived: %d, bArrived: %d\n", semcount(aArrived), semcount(bArrived));
    wait(bArrived);
	signal(aArrived);
	//kprintf("a1() -> aArrived: %d, bArrived: %d\n", semcount(aArrived), semcount(bArrived));
    kprintf(" A2 ");
}

void b2(){
    kprintf(" B1 ");
	//kprintf("b1() -> aArrived: %d, bArrived: %d\n", semcount(aArrived), semcount(bArrived));
    signal(bArrived);
    wait(aArrived);
	//kprintf("b1() -> aArrived: %d, bArrived: %d\n", semcount(aArrived), semcount(bArrived));
    kprintf(" B2 ");
}
