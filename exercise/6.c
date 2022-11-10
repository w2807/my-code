#include<stdio.h>
#include<stdlib.h>
void in(int a);
int out(void);
int b[10]={0},*p1,*p2,*p3;
int main()
{
    p1=b;
    p2=&b[9];
    p3=b;
    int i,j;
    printf("input a number:");
    scanf("%d",&i);
    while(i!=-1)
    {
        if(i==0)
        {
            j=out();
            printf("the out number is %d\n",j);
        }
        else
        in(i);
        printf("input a number:");
        scanf("%d",&i);
    }
    printf("the program is over");
    return 0;
}
void in(int a)
{
    if(p1==p2)
    {
        printf("an error occured");
        exit(0);
    }
    *p1=a;
    p1++;
}
int out(void)
{
    if(p1==&b[0])
    {
        printf("an error occured");
        exit(0);
    }
    if(p3<p1)
    {
        p3++;
        return *(p3-1);
    }
    else
    {
        printf("an error occured");
        exit(0);
    }
}  