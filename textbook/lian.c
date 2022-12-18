#include<stdio.h>
#include<string.h>
int judge1(char c[])
{
    if(c[0]!='-'&&(c[0]<'0'||c[0]>'9'))
    return 0;
    int i;
    for(i=1;i<strlen(c);i++)
    {
        if(c[i]<'0'||c[i]>'9')
        break;
    }
    if(i<strlen(c))
    return 0;
    return 1;
}
int main()
{
    char s[100]={0};
    gets(s);
    printf("%d",judge1(s));
    return 0;
}