#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;
int counter = 0;
int main(){
    
    while (1){
        fork();
        counter++;
        printf("%d\n\n\n\n\n\n", counter);
    }
    return 0;
}