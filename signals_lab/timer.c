/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

time_t start;
int counter;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
}

void termination(int signum) {
  time_t end;
  end = time(NULL);
  int total = difftime(end, start);
  printf("\nProgram terminated\nExecuted %d times in %d seconds\n", counter, total);
  exit(0);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, termination);
  start = time(NULL);
  counter = 0;
  while(1){
    alarm(1);
    sleep(1);
    printf("Turing was right!\n");
    counter++;
  };
   //busy wait for signal to be delivered
  return 0; //never reached
}