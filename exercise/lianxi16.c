#include<stdio.h>
#include<string.h>
int main()
{
    char str[20]={0},str1[20]={0};
    int i,j;
    printf("input a string:");
    gets(str);
    strcpy(str1,str);
    for(i=0,j=0;i<strlen(str);i++)
    if(str1[i]>='0'&&str1[i]<='9')
    {
        str[j++]='@';
        str[j++]=str1[i];
    }
    else
    str[j++]=str1[i];
    str[j]='\0';
    puts(str);
    return 0;
}