#include<stdio.h>
#include<stdlib.h>
long u,v;
void addrat(int a,int b)
{
    u=u*b+v*a;
    v*=b;
}
void lowterm()
{
    int numcopy,dencopy;
    int remainder;
    numcopy=u;
    dencopy=v;
    while(dencopy!=0)
    {
        remainder=numcopy%dencopy;
        numcopy=dencopy;
        dencopy=remainder;
    }
    if(numcopy!=0)
    {
        u/=numcopy;
        v/=numcopy;
    }
}
int main()
{
    int n,nterm;
    label:printf("\n输入调和级数的项数：\n");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("你他妈的输错了！\n");
        goto label;
    }
    else
    {
        u=0;
        v=1;
        for(nterm=1;nterm<=n;nterm++)
        {
            addrat(1,nterm);
            lowterm();
            printf("%d个项数数的和：%d/%d\n",nterm,u,v);
        }
    }
    return 0;
}