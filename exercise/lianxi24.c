#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main()
{
    char *a,c;
    int i;
    a=(char*)malloc(100);
    printf("input a string and a character:");
    gets(a);
    scanf("%c",&c);
    for(i=0;i<strlen(a);i++)
    if(a[i]!=c)
    printf("%c",a[i]);
    return 0;
}