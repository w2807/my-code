#include<stdio.h>
#include<stdlib.h>
int max(int,int),min(int,int),add(int,int),cheng(int,int),chu(int,int);
void process(int,int,int (*fun)());
int main()
{
    int a,b;
    scanf("%d,%d",&a,&b);
    process(a,b,max);
    process(a,b,min);
    process(a,b,add);
    process(a,b,cheng);
    process(a,b,chu);
    return 0;
}
void process(int x,int y,int (*fun)())
{
    int result;
    result=(*fun)(x,y);
    printf("%d\n",result);
}
int max(int x,int y)
{
    printf("max=");
    return (x>y?x:y);
}
int min(int x,int y)
{
    printf("min=");
    return (x<y?x:y);
}
int add(int x,int y)
{
    printf("sum=");
    return (x+y);
}
int cheng(int x,int y )
{
    printf("cheng=");
    return (x*y);
}
int chu(int x,int y)
{
    printf("chu=");
    return (x/y);
}