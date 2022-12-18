#include<stdio.h>
#include<string.h>
#include<malloc.h>
char *chu(int (*a1)[1000],int (*a2)[1000],int l1,int l2);
void sub(int (*a1)[1000],int (*a2)[],int* l1,int l2);
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
int judge1(char s[])
{
    if(s[0]=='-')
    return 0;
    return 1;
}
int judge2(char s1[],char s2[],int l1,int l2);
char s1[1000],s2[1000];
int main()
{
    gets(s1);
    gets(s2);
    int a1[1000]={0},a2[1000]={0},i,j,l1,l2;
    if(!judge1(s1))
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
    if(!judge1(s2))
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
    p=chu(&a1,&a2,l1,l2);
    puts(p);
    return 0;
}
void sub(int (*a1)[1000],int (*a2)[1000],int* l1,int l2)
{
    int i;
    for(i=0;i<*l1;i++)
    {
        if((*a1)[i]<(*a2)[i])
        {
            (*a1)[i]=10+(*a1)[i]-(*a2)[i];
            ((*a1)[i+1])--;
        }
        else
        (*a1)[i]=(*a1)[i]-(*a2)[i];
    }
    for(i=*l1-1;i>=0;i--)
    {
        if((*a1)[i])
        break;
        else
        (*l1)--;
    }
}
char *chu(int (*a1)[1000],int (*a2)[1000],int l1,int l2)
{
    if((judge2(s1,s2,l1,l2)<0||(*a1)[l1-1]==0)&&(*a2)[l2-1]!=0)
    return "0";
    else if((*a2)[l2-1]==0)
    return "error:can't divided by 0";
    static char b[1000]={0};
    int i,j=0,l=l1-l2+1,c[1000]={0};
    for(i=l2-1;i>=0;i--)
    (*a2)[i+l-1]=(*a2)[i];
    for(i=0;i<l-1;i++)
    (*a2)[i]=0;
    l2=l1;
    char c1[1000],c2[1000];
    for(i=0;i<l1;i++)
    c1[i]=(*a1)[l1-1-i]+'0';
    for(i=0;i<l2;i++)
    c2[i]=(*a2)[l2-1-i]+'0';
    for(i=0;i<l;i++)
    {
        while(judge2(c1,c2,l1,l2)>=0)
        {
            sub(&(*a1),&(*a2),&l1,l2);
            c[l-i-1]++;
            memset(c1,0,sizeof(c1));
            for(j=0;j<l1;j++)
            c1[j]=(*a1)[l1-1-j]+'0';
        }
        if(judge2(c1,c2,l1,l2)<0&&(*a2)[0]==0)
        {
            for(j=1;j<l2;j++)
            (*a2)[j-1]=(*a2)[j];
            (*a2)[j-1]=0;
            l2--;
            memset(c2,0,sizeof(c2));
            for(j=0;j<l2;j++)
            c2[j]=(*a2)[l2-1-j]+'0';
        }
    }
    while(l>1&&c[l-1]==0)
    l--;
    reverse(c,c+l-1);
    if((judge1(s1)&&judge1(s2))||((!judge1(s1))&&(!judge1(s2))))
    for(i=0;i<l;i++)
    b[i]=c[i]+'0';
    else if((judge1(s1)&&(!judge1(s2)))||((!judge1(s1))&&judge1(s2)))
    {
        b[0]='-';
        for(i=1,j=0;i<l+1&&j<l;i++,j++)
        b[i]=c[j]+'0';
    }
    return b;
}
int judge2(char c1[],char c2[],int l1,int l2)
{
    if(l1<l2)
    return -1;
    if(l1>l2)
    return 1;
    return strcmp(c1,c2);
}