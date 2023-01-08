#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	printf("Hello, I'm exec program!");
	getchar();
	execl("./another", "./another", NULL);
	return 1;
}

