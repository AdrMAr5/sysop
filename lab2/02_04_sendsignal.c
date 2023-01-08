#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main(int argc, char **argv) {
	int _pid = atoi(argv[1]);
	int _signalNumber = atoi(argv[2]);

	kill(_pid, _signalNumber);
	return 0;
}
