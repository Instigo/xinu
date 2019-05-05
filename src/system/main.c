/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

sid32 semaphore = 0;

int main(int argc, char **argv)
{
	uint32 retval;
    semaphore = semcreate(0);
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */

	recvclr();
	while (TRUE) {
		retval = receive();
		kprintf("\n\n\rMain process recreating shell\n\n\r");
		resume(create(shell, 4096, 1, "shell", 1, CONSOLE));
	}
	while (1);

	return OK;
}
