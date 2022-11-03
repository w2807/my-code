#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10]={1,2,3,2,34,45,12,2312,321,21},j,k,t;
    for(j=0;j<10;j++)
    for(k=0;k<9-j;k++)
    {
        if(a[k]==a[k+1])
        continue;
        if(a[k]>a[k+1])
    {
        t=a[k];
        a[k]=a[k+1];
        a[k+1]=t;
    }
    }
    for(j=0;j<10;j++)
    printf("%d ",a[j]);
    return 0;
}