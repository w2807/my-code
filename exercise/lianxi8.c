#include<stdio.h>
#include<stdlib.h>
int chazhao(int a[],int start,int end,int b);
int main()
{
    int a[10]={12,321,21,23,1,31,23,34,54,5},i,j,k,min,b;
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
    scanf("%d",&b);
    int c=chazhao(a,0,9,b);
    printf("%d",c);
    return 0;
}
int chazhao(int a[],int start,int end,int b)
{
    int mid;
    for(;start<=end;)
    {
        mid=(start+end)/2;
        if(b==a[mid])
        return mid;
        if(b>a[mid])
        start=mid+1;
        if(b<a[mid])
        end=b-1;
    }
    return -1;
}