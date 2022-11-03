#include<stdio.h>
#include<stdlib.h>
int Fibonacci(int a);
int main()
{
    printf("第几项？\n");
    int a,b;
    scanf("%d",&a);
    b=Fibonacci(a);
    printf("%d",b);
    return 0;
}
int Fibonacci(int a)
{
    int b;
    if(a==1||a==2)
    b=1;
    else
    b=Fibonacci(a-1)+Fibonacci(a-2);
    return b;
}