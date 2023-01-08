#include <stdio.h>
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
    int size = stoi(argv[1]);
    printf("przed alokacja");
    getchar();
    double* (a[size]);
    for(int i=0; i<size; i++){
        a[i] = new double[1000];
    }

    printf("po alokacji\n");
    getchar();
    
    for(int i=0; i<size; i++){
        free(a[i]);
    }
    printf("po zwolnieniu pamieci\n");
    getchar();
    
    return 0;
}