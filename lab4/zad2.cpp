#include <stdio.h>
#include <stdlib.h>

char x;

void statyczna(){ 
    double tablica[1000000];
    for(int i=0; i<1000000; i++){
        tablica[i] = 1;
    }
}

void dynamiczna(){
    double *tablica;
    tablica = malloc((size_t) sizeof(double)*1000000);
    for(int i=0; i<1000000; i++){
        tablica[i] = 1;
    }
    getchar();
    free(tablica);
}

int main(void){
    getchar();
    printf("statyczna:\n");
    statyczna();
    printf("\n");

    getchar();
    printf("dynamiczna:\n");
    dynamiczna();
    printf("\n");

    getchar();

    return 0;

}