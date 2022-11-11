#include<stdio.h>
int erfen(int a[],int b,int start,int end);
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10},i,j;
    printf("input a number:");
    scanf("%d",&i);
    j=erfen(a,i,0,9);
    if(j==-1)
    printf("not found\n");
    else
    printf("a[%d]=%d",j,i);
    return 0;
}
int erfen(int a[],int b,int start,int end)
{
    int *p=a,mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(b==*(p+mid))
        return mid;
        else if(b>*(p+mid))
        start=mid+1;
        else if(b<*(p+mid))
        end=mid-1;
    }
    return -1;
}