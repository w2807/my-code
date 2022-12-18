#include<stdio.h>
#include<string.h>
#include<malloc.h>
char *cheng(int a1[],int a2[],int l1,int l2);
void reverse(int *strat,int *end);
int judge1(char s[])
{
    if(s[0]=='-')
    return 0;
    return 1;
}
char s1[1000]={0},s2[1000]={0};
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
    p=cheng(a1,a2,l1,l2);
    puts(p);
    return 0;
}
char *cheng(int a1[],int a2[],int l1,int l2)
{
    int c[2000]={0},d[2000]={0};
    static char b[2000]={0};
    int i=0,j=0,k,l;
    l=a1[l1-1]*a2[l2-1];
    if(l>=10)
    l=l1+l2;
    else
    l=l1+l2-1;
    for(i=0;i<l;i++)
    {
        for(j=i,k=0;j<l&&k<l;j++,k++)
        {
            c[j]+=((a1[i]*a2[k])%10);//记录每个数乘完的个位
            d[j]=((a1[i]*a2[k])/10)%10;//记录每个数乘完的十位
        }
        for(j=0;j<l;j++)
        if(d[j])
        {
            c[j+1]=c[j+1]+d[j];
            d[j]=0;
        }
    }
    for(i=0;i<l;i++)
    if(c[i]>=10)
    {
        j=(c[i]/10)%10;
        c[i+1]=c[i+1]+j;
        c[i]=c[i]%10;
    }
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