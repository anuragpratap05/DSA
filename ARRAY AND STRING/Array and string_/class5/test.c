#include<stdio.h>
#define square(x) x*x
int main()
{
    int a=5;
    void *ptr=&a;
    printf("%f",*(float*)ptr);
    
    

    return 0;
}