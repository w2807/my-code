#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,k,l,m,max,min;
    printf("input n:");
    scanf("%d",&n);
    int a[n][n];
    printf("input array:\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    {
        max=a[i][0];
        for(j=0;j<n;j++)
        if(a[i][j]>max)
        {
            max=a[i][j];
            k=j;
        }
        min=a[i][k];
        for(l=0;l<n;l++)
        if(a[l][k]<min)
        {
            min=a[l][k];
            m=l;
        }
        if(max==min)
        break;
    }
    if(max==min)
    printf("a[%d][%d]=%d",m,k,max);
    else
    printf("NO");
    return 0;
}