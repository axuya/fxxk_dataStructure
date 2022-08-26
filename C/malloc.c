#include<stdio.h>
#include<stdlib.h>

int main(){
    int * p1 = malloc(4 * sizeof(int));
    int * p2 = malloc(sizeof(int[4]));
    int * p3 = malloc(4 * sizeof *p3);

    if(p1 != 0){
        for (int n = 0; n < 4; n++)
        {
            p1[n] = n * n;
        }
        for (int n = 0; n < 4; n++)
        {
            printf("p1[%d] == %d\n",n,p1[n]);
        }
    }
    free(p1);
    free(p2);
    free(p3);
}