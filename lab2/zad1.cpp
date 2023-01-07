#include<sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<fstream>
using namespace std;

int main(){
    ofstream myfile;
    myfile.open ("example.txt");
    int tab1[1000];
    int* tab2 = new int[1000];
    pid_t pid;
    /*fork a child process*/
    pid = fork();
    if (pid <0){
        fprintf(stderr, "Fork failed");
    }
    else if(pid == 0){ //child process
        printf("%ld\t%ld\n", (long)getpid(), (long)getppid());
        // execlp("/bin/ls", "ls", NULL);
        getchar();
    }
    else{
        /*parent will wait for the child to complete*/
        // wait(NULL);
        // getchar();
        printf("%ld\t%ld\n", (long)getpid(), (long)getppid());
        printf("child complete\n");
    }

    return 0;
}