#include<stdio.h>
#include<stdlib.h>
int f(int a);
int main()
{
    int a,b;
    printf("input a number:");
    scanf("%d",&a);
    b=f(a);
    if(b==1)
    printf("the number is a prime number");
    else
    printf("the number isn't a prime number");
    return 0;
}
int f(int a)
{
    int b;
    if(a==1)
    return 0;
    for(b=2;b<a;b++)
    {
        if(a%b!=0)
        continue;
        else
        return 0;
    }
    return 1;
}