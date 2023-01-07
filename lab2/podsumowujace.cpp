#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;
int main(){
    long int ctr = 1;
	pid_t pid;

	while (1) {
		pid = fork();
		
		if (pid == 0) {
			while (1)
				sleep(1);
				
		} else if (pid > 0) {
			ctr += 1;
			printf("procesy: %ld\n", ctr);
	
		} else {
			printf("fork fail\tprocesy: %ld\n", ctr);
			sleep(1);
		}
    }
	usleep(1000);
    return 0;
}