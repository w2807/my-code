#include<stdio.h>
#include<string.h>
int main()
{
    char s1[100];
    int a1[100],i;
    gets(s1);
    for(i=0;i<strlen(s1);i++)
    a1[i]=s1[i]-'0';
    for(i=0;i<strlen(s1);i++)
    printf("%d",a1[i]);
    return 0;
}