#include<stdio.h>

int main(){
    int a = 100;
    int *p_a = &a;
    printf("%d\n",a);
    printf("%d\n",&a);
    printf("%d\n",*p_a);
    printf("%d\n",&p_a);
    return 0;
}