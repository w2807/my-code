#include<stdio.h>
#include<string.h>
int main()
{
    char a[10]={0};
    int i;
    printf("input a string:");
    gets(a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>=65&&a[i]<=90)
        {
            a[i]=a[i]+32;
            continue;
        }
        if(a[i]>=97&&a[i]<=122)
        a[i]=a[i]-32;
    }
    for(i=0;i<strlen(a);i++)
    printf("%c",a[i]);
    return 0;
}