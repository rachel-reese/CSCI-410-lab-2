#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>

#define   MAX_COUNT  3
#define   BUF_SIZE   100

void  main(void)
{
     pid_t  pid, mypid;
     int    i;
     char   buf[BUF_SIZE];

     for (i = 1; i <= MAX_COUNT; i++) {
          mypid = fork();
          pid = getpid();

          sprintf(buf, "This line is from pid %d, new fork pid %d, value = %d\n", pid, mypid, i);
          write(1, buf, strlen(buf));
     } 
}