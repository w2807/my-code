#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,*p=&a;
    a=5;
    printf("a=%d",a);
    *p=10;
    printf("a=%d",a);
    return 0;
}