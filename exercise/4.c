#include<stdio.h>
#include<malloc.h>
int main()
{
    char c;
    int i,*a,j,k,min,temp;
    a=(int*)malloc(100);
    printf("input an array:");
    for(i=0;c!='\n';i++)
    {
        scanf("%d",&a[i]);
        c=getchar();
    }
    for(j=0;j<i;j++)
    {
        min=j;
        for(k=j+1;k<i;k++)
        if(a[k]<a[min])
        min=k;
        if(min!=j)
        {
            temp=a[j];
            a[j]=a[min];
            a[min]=temp;
        }
    }
    for(j=0;j<i;j++)
    printf("%d ",a[j]);
    return 0;
}