#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAX 1000
char *jia(int a1[],int a2[],int l1,int l2);
char *jian(int a1[],int a2[],int l1,int l2);
char *cheng(int a1[],int a2[],int l1,int l2);
char *chu(int a1[],int a2[],int l1,int l2);    //除法只返回得数的整数部分
void reverse(int *sat,int *end);  //将数组中的各个数字反向
int judge1(char s[])    //判断输入的数是否是负数
{
    if(s[0]=='-')
    return 0;
    return 1;
}
int judge2(int a1[],int a2[],int l1,int l2);    //判断输入的两个数字哪个更大
char s1[MAX],s2[MAX];
int main()
{
    char *p1;
    p1=(char)malloc(2*MAX);
    printf("输入两个整数:");
    gets(s1);
    gets(s2);
    int l1,l2,i,j,k,a1[MAX]={0},a2[MAX]={0};  
    if(!judge1(s1))    //将输入的字符串转移到整型数组，方便算，反着存储可以方便后续的进位运算
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
    printf("选择运算类型(1加法,2减法,3乘法,4除法)");
    scanf("%d",&k);
    switch(k)
    {
        case 1:
        {
            p1=jia(a1,a2,l1,l2);
            break;
        }
        case 2:
        {
            p1=jian(a1,a2,l1,l2);
            break;
        }
        case 3:
        {
            p1=cheng(a1,a2,l1,l2);
            break;
        }
        case 4:
        {
            p1=chu(a1,a2,l1,l2);
            break;
        }
    }
    printf("运算结果为:");
    puts(p1);
    return 0;
}
char *jia(int a1[],int a2[],int l1,int l2)
{
    int c[2*MAX]={0};
    static char b[2*MAX]={0};   //定义为static可以让函数返回该数组
    int i=0,j=0,l;
    if(l1>=l2)
    l=l1;
    else
    l=l2;
    for(i=0;i<l;i++)
    {
        c[i]=a1[i]+a2[i];
        if(c[i]>=10)   //进位运算
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
    for(i=0;i<200&&j>=0;j--,i++)  //再存储到字符串中方便输出
    b[i]=c[i]+'0';
    return b;
}
char *jian(int a1[],int a2[],int l1,int l2)
{
    int c[2*MAX]={0};
    static char b[2*MAX];
    int i=0,j=0,l;
    l=(l1>=l2)?l1:l2;
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
}
char *cheng(int a1[],int a2[],int l1,int l2)
{
    int c[2*MAX],d[2*MAX];
    static char b[MAX*MAX]; 
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
            c[j]+=((a1[i]*a2[k])%10);      //记录每个数乘完的个位
            d[j]=((a1[i]*a2[k])/10)%10;    //记录每个数乘完的十位
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
char *chu(int a1[],int a2[],int l1,int l2)
{

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