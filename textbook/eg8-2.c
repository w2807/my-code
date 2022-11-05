#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int a;
    char *s;
    printf("input a string and reverse it:");
    s=(char*)malloc(80);
    if(!s)
    {
        printf("memory requst failed");
        exit(1);
    }
    gets(s);
    for(a=strlen(s)-1;a>=0;a--)
    printf("%c",s[a]);
    free(s);
    return 0;
}