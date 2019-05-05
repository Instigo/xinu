#include <xinu.h>

shellcmd xsh_wait(int nargs, char *args[]) 
{

    pid32 pid;
    pri16 priority;

    priority = INITPRIO;

    pid = resume(create(mywait, 1024, priority, "Test", 0));
    return 0;
}