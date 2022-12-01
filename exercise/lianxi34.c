#include<stdio.h>
#include<string.h>
#include<malloc.h>
char *jian(int a1[],int a2[],int l1,int l2);
int judge2(int a1[],int a2[],int l1,int l2);
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
char s1[1000]={0},s2[1000]={0};
int main()
{
    gets(s1);
    gets(s2);
    int l1=strlen(s1),l2=strlen(s2),i,j,a1[1000]={0},a2[1000]={0};
    for(i=0,j=l1-1;i<l1&&j>=0;i++,j--)
    a1[j]=s1[i]-'0';
    for(i=0,j=l2-1;i<l2&&j>=0;i++,j--) 
    a2[j]=s2[i]-'0';
    char *p;
    p=(char*)malloc(2000);
    p=jian(a1,a2,l1,l2);
    puts(p);
    return 0;
}
char *jian(int a1[],int a2[],int l1,int l2)
{
    if(!judge2(a1,a2,l1,l2))
    {
        int *p1,*p2,tmp,i,l=(l1>=l2)?l1:l2;
        p1=a1;
        p2=a2;
        for(i=0;i<l;i++)
        {
            tmp=*(p1+i);
            *(p1+i)=*(p2+i);
            *(p2+i)=tmp;
        }
        tmp=l2;
        l2=l1;
        l1=tmp;
    }
    int c[2000]={0};
    static char b[2000];
    int i=0,l;
    l=l1;
    for(i=0;i<l;i++)
    {
        if(a1[i]<a2[i])
        {
            a1[i+1]=a1[i+1]-1;
            c[i]=10+a1[i]-a2[i];
        }
        else
        c[i]=a1[i]-a2[i];
    }
    for(i=l;i>=0;i--)
    if(a1[i]<=a2[i])
    l--;
    else
    break;
    reverse(c,c+l);
    for(i=0;i<2000&&l>=0;l--,i++)
    b[i]=c[i]+'0';
    return b;
}
int judge2(int a1[],int a2[],int l1,int l2)
{
    if(l1<l2)
    return 0;
    if(l1>l2)
    return 1;
    int i,j=0;
    for(i=l1-1;i>=0;i--)
    {
        if(a1[i]>=a2[i])
        j++;
        else
        break;
    }
    if(j==l1)
    return 1;
    return 0;
}