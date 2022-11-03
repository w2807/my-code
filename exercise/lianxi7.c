#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10]={12,321,21,23,1,31,23,34,54,5},i,j,k,min;
    for(i=0;i<9;i++)
    {
        min=i;
        for(j=i+1;j<10;j++)
        if(a[j]<a[min])
        min=j;
        if(i!=min)
        {
            k=a[i];
            a[i]=a[min];
            a[min]=k;
        }
    }
    for(i=0;i<10;i++)
    printf("%d ",a[i]);
    return 0;
}