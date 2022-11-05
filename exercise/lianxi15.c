#include<stdio.h>
#include<string.h>
int substiute(char a,char b,char c[])
{
    int i,j=strlen(c),k=0;
    for(i=0;i<j;i++)
    {
        if(c[i]==a)
        {
            c[i]=b;
            k++;
        }
    }
    return k;
}
int main()
{
    char a='b',b='c',c[20]={0};
    printf("input a string:");
    gets(c);
    int i=substiute(a,b,c);
    puts(c);
    printf("%d",i);
    return 0;
}