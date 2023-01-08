#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	printf("Hello, I'm system program!");
	getchar();
	system("ls -al /var/log/");
	return 1;
}

