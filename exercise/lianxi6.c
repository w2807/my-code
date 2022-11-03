#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[15]={3,44,38,5,47,15,36,26,27,213,23,12,23,34,66},i,j,k;
    for(i=1;i<15;i++)
    {
        j=a[i];
        for(k=i;k>0;k--)
        if(a[k-1]>j)
        a[k]=a[k-1];
        else break;
        a[k]=j;
    }
    for(i=0;i<15;i++)
    printf("%d ",a[i]);
    return 0;
}