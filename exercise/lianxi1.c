#include<stdio.h>
#include<stdlib.h>
int max(int a,int b); 
int main()
{
    int m,n,a;
    printf("输入两个数：");
    scanf("%d,%d",&m,&n);
    a=max(m,n);
    printf("%d\n",a);
    return 0;
}
int max(int a,int b)
{
    int c;
    if(a>b)
    c=a;
    else
    c=b;
    return c;
}