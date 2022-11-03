#include<stdio.h>
#include<string.h>
int main()
{
    char a[30]={0},b[10]={0};
    int i,j,k,l;
    printf("input two string:");
    gets(a);
    gets(b);
    k=strlen(a);
    l=strlen(b);
    for(i=k,j=0;i<k+l&&j<l;i++,j++)
    a[i]=b[j];
    puts(a);
    return 0;
}