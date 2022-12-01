#include<stdio.h>
#include<string.h>
#include<malloc.h>
char *jia(int a1[],int a2[],int l1,int l2,int n1,int n2);   //加两个表示符号的参数
char *jian(int a1[],int a2[],int l1,int l2,int n1,int n2);
void reverse(int *start,int *end);
int judge1(char s[])
{
    if(s[0]=='-')
    return 0;
    return 1;
}
int judge2(char s1[],char s2[],int l1,int l2);
char s1[1000]={0},s2[1000]={0};
int main()
{
    gets(s1);
    gets(s2);
    int a1[1000]={0},a2[1000]={0},i,j,k,l1,l2;
    char *p;
    p=(char*)malloc(2000);
    scanf("%d",&k);
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
    switch(k)
    {
        case 1:
        {
            p=jia(a1,a2,l1,l2,judge1(s1),judge1(s2));
            break;
        }
        case 2:
        {
            p=jian(a1,a2,l1,l2,judge1(s1),judge1(s2));
            break;
        }
    }
    puts(p);
    return 0;
}
char *jian(int a1[],int a2[],int l1,int l2,int n1,int n2)
{
    char *p1;
    p1=(char*)malloc(2000);
    if(((!n1)&&(n2))||((n1)&&(!n2)))
    p1=jia(a1,a2,l1,l2,1,1);
    static char b[2000]={0};
    int i,j;
    if((!n1)&&n2)
    {
        b[0]='-';
        for(i=1,j=0;i<strlen(p1)+1&&j<strlen(p1);i++,j++)
        b[i]=*(p1+j);
        return b;
    }
    else if(n1&&(!n2))
    {
        for(i=0;i<(strlen(p1));i++)
        b[i]=*(p1+i);
        return b;
    }
    if(!judge2(s1,s2,l1,l2))
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
    }
    int c[2000]={0};
    int l;
    l=(l1>l2)?l1:l2;i=0;j=0;
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
    if(l1==l2)
    while(l>1&&c[l-1]==0)
    l--;
    reverse(c,c+l-1);
    if((((!judge1(s1))&&(!judge1(s2)))&&(judge2(s1,s2,l1,l2)))||(judge1(s1)&&judge1(s2)&&(!judge2(s1,s2,l1,l2))))
    {
        b[0]='-';
        for(i=1,j=0;i<l+1&&j<l;i++,j++)
        b[i]=c[j]+'0';
        return b;
    }
    for(i=0;i<l;i++)
    b[i]=c[i]+'0';
    return b;
}
int judge2(char s1[],char s2[],int l1,int l2)//还是应该分三种情况返回，去你妈的草
{
    int i,j=0;
    char c1[1000],c2[1000];
    strcpy(c1,s1);strcpy(c2,s2);
    if(!judge1(c1))
    for(i=0;i<strlen(c1);i++)
    c1[i]=c1[i+1];
    if(!judge1(c2))
    for(i=0;i<strlen(c2);i++)
    c2[i]=c2[i+1];
    if(l1<l2)
    return 0;
    else if(l1>l2)
    return 1;
    for(i=l1-1;i>=0;i--)
    {
        if(c1[i]>=c2[i])
        j++;
        else
        break;
    }
    if(j==l1)
    return 1;
    return 0;
}
char *jia(int a1[],int a2[],int l1,int l2,int n1,int n2)
{
    char *p;
    static char b[2000]={0};
    int i=0,j=0;
    p=(char*)malloc(2000);
    if(((!n1)&&n2)||(n1&&(!n2)))
    p=jian(a1,a2,l1,l2,1,1);
    if((((!n1)&&n2)&&(!judge2(s1,s2,l1,l2)))||((n1&&(!n2))&&(judge2(s1,s2,l1,l2))))
    {
        for(i=0;i<strlen(p);i++)
        b[i]=*(p+i);
        return b;
    }
    else if((((!n1)&&n2)&&(judge2(s1,s2,l1,l2)))||((n1&&(!n2))&&(!judge2(s1,s2,l1,l2))))
    {
        b[0]='-';
        for(i=1,j=0;i<strlen(p)+1;i++,j++)
        b[i]=*(p+j);
        return b;
    }
    int c[2000]={0},l,k;
    if(l1>=l2)
    l=l1;
    else
    l=l2;
    for(i=0;i<l;i++)
    {
        c[i]=a1[i]+a2[i];
        if(c[i]>=10)
        {
            j=(c[i]/10)%10;
            c[i+1]=c[i+1]+j;
            c[i]=c[i]%10;
        }
    }
    if(c[i])
    {
        reverse(c,c+i);
        j=i;
    }
    else
    {
        reverse(c,c+i-1);
        j=i-1;
    }
    if((!judge1(s1))&&(!judge1(s2)))
    {
        b[0]='-';
        for(i=1,k=0;j>=0;i++,k++,j--)
        b[i]=c[k]+'0';
        return b;
    }
    for(i=0;i<2000&&j>=0;j--,i++)
    b[i]=c[i]+'0';
    return b;
}
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