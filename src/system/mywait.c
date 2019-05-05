#include <xinu.h>

extern sid32 semaphore;

void mywait(void){
    kprintf("xsh_wait() called, semaphore count: %d\n", semcount(semaphore));
    wait(semaphore);

}