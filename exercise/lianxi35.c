#include<stdio.h>
#include<string.h>
#include<malloc.h>
char *chu(char s1[],char s2[],int l1,int l2);
void reverse(int *start,int *end)
{
    while (start<end)
    {
        int tmp=*start;
        *start=*end;
        *end=tmp;
        start++;
        end--;
    }
}
int judge(char s[])
{
    if(s[0]=='-')
    return 0;
    return 1;
}
char s1[1000],s2[1000];
int main()
{
    gets(s1);
    gets(s2);
    int a1[1000]={0},a2[1000]={0},i,j,l1,l2;
    if(!judge(s1))
    {
        l1=strlen(s1)-1;
        for(i=1,j=l1-1;i<l1+1&&j>=0;i++,j--)
        a1[j]=s1[i]-'0';
    }
    else
    {
        l1=strlen(s1);
        for(i=0,j=l1-1;i<l1&&j>=0;i++,j--)
        a1[j]=s1[i]-'0';
    }
    if(!judge(s2))
    {
        l2=strlen(s2)-1;
        for(i=1,j=l2-1;i<l2+1&&j>=0;i++,j--)
        a2[j]=s2[i]-'0';
    }
    else
    {
        l2=strlen(s2);
        for(i=0,j=l2-1;i<l2&&j>=0;i++,j--)
        a2[j]=s2[i]-'0';
    }
    char *p;
    p=(char*)malloc(2000);
    p=cheng(a1,a2,l1,l2);
    puts(p);
    return 0;
}
char *chu(char s1[],char s2[],int l1,int l2)
{
    
}