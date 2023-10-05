#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <time.h>

void  ChildProcess(void);                /* child process prototype  */

void  main(void)
{
     pid_t  pid1, pid2;
     time_t t;
     srandom(time(&t));
     pid1 = fork();
     if (pid1 == 0) {
        ChildProcess();
        exit(0);
     }     
     else { 
      pid2 = fork();
      if (pid2 == 0) {
        ChildProcess();
        exit(0);
      }
      else { 
        waitpid(pid1);
        printf("\nChild Pid: %d has completed!\n", pid1);
        waitpid(pid2);
        printf("\nChild Pid: %d has completed!\n", pid2);
       }
     }       
}

void  ChildProcess(void)
{
     int   i;
     int pid = getpid();
     int ppid = getppid();
     for (i = 1; i <= random() % 31; i++)
          printf("Child Pid: %d is going to sleep!\n", pid);
          sleep(random() % 10);
          printf("\nChild Pid: %d is awake!\nWhere is my parent Parent: %d?\n", pid, ppid);
     exit(0);
}