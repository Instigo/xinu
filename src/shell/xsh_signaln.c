/* xsh_signaln.c - xsh_signaln */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

extern sid32 semaphore;  // this is defined elsewhere

shellcmd xsh_signaln(int nargs, char *args[])
{
    char	*chptr;			/* walks through argument	*/
	char	ch;			/* next character of argument	*/
    int32    signalCount;   /* stores the signalCount value     */
    pid32    pid;

    if (nargs > 2) {
		fprintf(stderr, "%s: too many arguments\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
				args[0]);
		return 1;
	}

	if (nargs != 2) {
		fprintf(stderr, "%s: argument in error\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
				args[0]);
		return 1;
	}

    chptr = args[1];
	ch = *chptr++;
	signalCount = 0;
	while (ch != NULLCH) {
		if ( (ch < '0') || (ch > '9') ) {
			fprintf(stderr, "%s: nondigit in argument\n",
				args[0]);
			return 1;
		}
		signalCount = 10*signalCount + (ch - '0');
		ch = *chptr++;
	}

    // call the existing signaln()
    signaln(semaphore, signalCount);
}