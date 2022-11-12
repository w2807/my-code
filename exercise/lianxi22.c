#include<stdio.h>
#include<malloc.h>
int stringlen(char *a)
{
    int i,j=0;
    for(i=0;;i++)
    if(a[i]!='\0')
    j++;
    else
    break;
    return j;
}
int main()
{
    char *a;
    a=(char*)malloc(100);
    int b;
    printf("input a string:");
    gets(a);
    b=stringlen(a);
    printf("%d",b);
    return 0;    
}