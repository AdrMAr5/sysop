#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){
	printf("Parent PID: %d\n", getpid());
	int b = fork();
	if (b == 0) {
		printf("Child PID: %d\n", getpid());
		printf("Child's parent PID: %d\n", getppid());
		int c = fork();
		if (c == 0) {
			printf("Grandchild PID: %d\n", getpid());
			printf("Parent's grandchild PID: %d\n", getppid());
		}
	}
	else if (b > 0){
		system("pstree");
	}
	getchar();
	return 0;
}

