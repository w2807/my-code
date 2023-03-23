#include<stdio.h>
#include<time.h>
int ziliehe(int a[],int n);
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    int i;
    i=ziliehe(a,n);
    printf("the max sum is %d",i);
    return 0;
}
int ziliehe(int a[],int n)
{
    int thissum=0,maxsum=0;
    int i;
    for(i=0;i<n;i++)
    {
        thissum+=a[i];
        if(thissum>maxsum)
        maxsum=thissum;
        else if(thissum<0)
        thissum=0;
    }
    return maxsum;
}