#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int signum) {
   printf("Caught signal %d, coming out...\n", signum);
   exit(signum);
}

int main() {
   signal(SIGINT, sighandler);
   while(1)
   {
      printf("...\n");
      sleep(2);
   }
   return(0);
}
