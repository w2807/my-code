#include<stdio.h>
int main()
{
    int a[10],*p;
    for(p=a;p<a+10;p++)
    scanf("%d",p);
    for(p=a;p<a+10;++p)
    printf("%5d",*p);
    return 0;
}