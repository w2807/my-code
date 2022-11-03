#include<stdio.h>
#include<stdlib.h>
int main()
{
    int array[10][10],n,i,j,k;
    printf("input n:");
    scanf("%d",&n);
    printf("input array:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&array[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(i==j)
            {
                if(array[i+1][j]==0)
                k=1;
                else
                {
                    k=0;
                    i=n;
                    break;
                }
            }
        }
    }
    if(k==1)
    printf("YES");
    else
    printf("NO");
    return 0;
}