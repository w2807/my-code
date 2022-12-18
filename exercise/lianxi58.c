#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mian main
char s1[1000],s2[1000];
char *chu(int a1[],int a2[],int l1,int l2);
int sub(int **a1,int **a2,int *l1,int *l2);
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
int judge2(int a1[],int a2[],int l1,int l2)
{
    int i;
    if(l1<l2)
        return -1;
    if(l1==l2)//若两个数位数相等
    {
        for(i=l1-1;i>=0;i--)
        {
            if(a1[i]=a2[i])//对应位的数相等
            continue;
            if(a1[i]>a2[i])//被除数 大于 除数，返回值为1
            return 1;
            if(a1[i]<a2[i])//被除数 小于 除数，返回值为-1
            return -1;
        }
    }
    return 0;//被除数 等于 除数，返回值为0
}
int mian()
{
    gets(s1);gets(s2);
    char c1[1000]={0},c2[1000]={0};
    int i,l1=strl(s1),l2=strl(s2),a1[1000]={0},a2[1000]={0};
    for(i=0;i<l1;i++)
    a1[i]=s1[i]-'0';
    for(i=0;i<l2;i++)
    a2[i]=s2[i]-'0';
    char *p=chu(a1,a2,l1,l2);
    puts(p);
    return 0;
}
char *chu(int a1[],int a2[],int l1,int l2)
{

    if((!judge2(a1,a2,l1,l2)||a1[0]==0)&&a2[0]!=0)
    return "0";
    else if(a2[0]==0)
    return "error:can't divide by 0";
    int c[1000]={0},yu[1000]={0},n[1000]=0,l=l1-l2,i,k=l1-l2;
    static char b[1000]={0};
    reverse(a1,a1+l1-1);
    reverse(a2,a2+l1-1);
    while(l1>=l2)
    {
        i=sub(&a1,&a2,&l1,&l2);//返回循环减的次数并对a1、l1进行修改
        n[l]=i;
        l=l1-l2;
    }
    reverse(n,n+k);
    for(i=0;i<k;i++)
    b[i]=n[i]+'0';
    return b;
}
int sub(int **a1,int **a2,int *l1,int *l2)
{
    int i;
    while(judge2(*a1,*a2,*l1,*l2)>0)
    {
        
    }
}