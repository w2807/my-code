#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAX 1000   //数字的最大位数
char *jia(int a1[],int a2[],int l1,int l2,int n1,int n2);   //后两个参数为两个数的符号
char *jian(int a1[],int a2[],int l1,int l2,int n1,int n2);
char *cheng(int a1[],int a2[],int l1,int l2,int n1,int n2);
char *chu(int (*a1)[MAX],int (*a2)[MAX],int l1,int l2,int n1,int n2);    //用数组指针可以方便对两个数进行修改，只能算整数部分
void reverse(int *sat,int *end);    //将数组中的各个数字反向
int judge(char c1[]);    //判断输入的数是否是负数
int compare(char c1[],char c2[],int l1,int l2);    //判断输入的两个数字哪个更大
void jian1(int (*a1)[MAX],int (*a2)[MAX],int* l1,int l2);    //该函数在除法中调用，用于以减法模拟除法
int judge1(char c[]);     //检查输入的函数
int main()
{
    char *p1,s1[MAX]={0},s2[MAX]={0};
    int l1,l2,i,j,k,a1[MAX]={0},a2[MAX]={0};
    printf("输入两个整数:\n");
    while(scanf("%s %s",s1,s2)==2)   //读入EOF时可以跳出循环并结束程序
    {
        p1=(char*)malloc(2*MAX);
        while(1)
        {
            if(judge1(s1)&&judge1(s2))
            break;
            else
            {
                printf("你输入的不对，请重来\n");
                scanf("%s %s",s1,s2);
            }
        }
        if(!judge(s1))    //将输入的字符串中的数字转移到整型数组，方便算，反着存储可以方便后续的进位运算
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
        i=1;
        while(i)
        {
            printf("选择运算类型(1加法,2减法,3乘法,4除法):\n");
            scanf("%d",&k);
            switch(k)
            {
                case 1:
                {
                    p1=jia(a1,a2,l1,l2,judge(s1),judge(s2));
                    i=0;
                    break;
                }
                case 2:
                {
                    p1=jian(a1,a2,l1,l2,judge(s1),judge(s2));
                    i=0;
                    break;
                }
                case 3:
                {
                    p1=cheng(a1,a2,l1,l2,judge(s1),judge(s2));
                    i=0;
                    break;
                }
                case 4:
                {
                    p1=chu(&a1,&a2,l1,l2,judge(s1),judge(s2));
                    i=0;
                    break;
                }
                default:
                {
                    printf("请重选\n");
                    break;
                }
            }
        }
        printf("运算结果为:");
        puts(p1);
        memset(s1,0,sizeof(s1));     //将各个数清零
        memset(s2,0,sizeof(s2));
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        memset(p1,0,2*MAX);
        printf("如果想结束程序，输入CTRL+Z并回车或者接着输入两个整数\n");
    }
    system("pause");
    return 0;
}
char *jia(int a1[],int a2[],int l1,int l2,int n1,int n2)
{
    int i=0,j=0;
    char *p,c1[MAX]={0},c2[MAX]={0};
    for(i=0;i<l1;i++)        //把数组存到字符串里可以在compare函数中调用strcmp函数方便比较数的大小
    c1[i]=a1[l1-1-i]+'0';
    for(i=0;i<l2;i++)
    c2[i]=a2[l2-1-i]+'0';
    if((((!n1)&&n2)||(n1&&(!n2)))&&compare(c1,c2,l1,l2)==0)
    return "0";
    static char b[2*MAX]={0};
    p=(char*)malloc(2*MAX);
    if((((!n1)&&n2)||(n1&&(!n2)))&&compare(c1,c2,l1,l2)>0)
    p=jian(a1,a2,l1,l2,1,1);
    else if((((!n1)&&n2)||(n1&&(!n2)))&&compare(c1,c2,l1,l2)<0)
    p=jian(a2,a1,l2,l1,1,1);
    if((((!n1)&&n2)&&(compare(c1,c2,l1,l2)<0))||((n1&&(!n2))&&(compare(c1,c2,l1,l2)>0)))    //判断是否用加负号
    {
        for(i=0;i<strlen(p);i++)
        b[i]=*(p+i);
        memset(p,0,2*MAX);
        return b;
    }
    else if((((!n1)&&n2)&&(compare(c1,c2,l1,l2)>0))||((n1&&(!n2))&&(compare(c1,c2,l1,l2)<0)))
    {
        b[0]='-';
        for(i=1,j=0;i<strlen(p)+1;i++,j++)
        b[i]=*(p+j);
        memset(p,0,2*MAX);
        return b;
    }
    int c[2*MAX]={0},l=(l1>=l2)?l1:l2,k;
    for(i=0;i<l;i++)    //先加好
    c[i]=a1[i]+a2[i];
    for(i=0;i<l;i++)    //再进位
    {
        if(c[i]>=10)
        {
            c[i+1]+=c[i]/10;
            c[i]=c[i]%10;
        }
    }
    if(c[i])     //判断加法所得数的位数
    {
        reverse(c,c+i);
        j=i;
    }
    else
    {
        reverse(c,c+i-1);
        j=i-1;
    }
    if((!n1)&&(!n2))      //添加负号
    {
        b[0]='-';
        for(i=1,k=0;j>=0;i++,k++,j--)
        b[i]=c[k]+'0';
        return b;
    }
    for(i=0;i<2*MAX&&j>=0;j--,i++)
    b[i]=c[i]+'0';
    return b;
}
char *jian(int a1[],int a2[],int l1,int l2,int n1,int n2)
{
    char *p1,c1[MAX]={0},c2[MAX]={0};
    int i,j;
    for(i=0;i<l1;i++)
    c1[i]=a1[l1-1-i]+'0';
    for(i=0;i<l2;i++)
    c2[i]=a2[l2-1-i]+'0';
    if(((n1&&n2)||((!n1)&&(!n2)))&&compare(c1,c2,l1,l2)==0)
    return "0";
    p1=(char*)malloc(2*MAX);
    if(((!n1)&&(n2))||((n1)&&(!n2)))
    p1=jia(a1,a2,l1,l2,1,1);
    static char b[2*MAX]={0};
    if((!n1)&&n2)
    {
        b[0]='-';
        for(i=1,j=0;i<strlen(p1)+1&&j<strlen(p1);i++,j++)
        b[i]=*(p1+j);
        memset(p1,0,2*MAX);
        return b;
    }
    else if(n1&&(!n2))
    {
        for(i=0;i<(strlen(p1));i++)
        b[i]=*(p1+i);
        memset(p1,0,2*MAX);
        return b;
    }
    if(compare(c1,c2,l1,l2)<0)     //如果第一个数更小就调换位置，一直用大的数字减小的数字
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
    int c[2*MAX]={0};
    int l;
    l=(l1>l2)?l1:l2;i=0;j=0;
    for(i=0;i<l;i++)
    {
        if(a1[i]<a2[i])
        {
            c[i]=a1[i]+10-a2[i];
            a1[i+1]=a1[i+1]-1;      //减法的借位
        }
        else
        c[i]=a1[i]-a2[i];
    }
    while(l>1&&c[l-1]==0)     //判断减法得数的位数
    l--;
    reverse(c,c+l-1);
    if((((!n1)&&(!n2))&&(compare(c1,c2,l1,l2)>=0))||(n1&&n2&&(compare(c1,c2,l1,l2)<0)))
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
char *cheng(int a1[],int a2[],int l1,int l2,int n1,int n2)
{
    if(a1[l1-1]==0||a2[l2-1]==0)
    return "0";
    int c[2*MAX]={0};
    static char b[MAX*MAX]={0};
    int i=0,j=0,l=l1+l2;
    for(i=0;i<l1;i++)
    for(j=0;j<l2;j++)
    c[j+i]+=a1[i]*a2[j];     //先全部都乘好
    for(i=0;i<l;i++)
    {
        if(c[i]>=10)        //再处理进位
        {
            c[i+1]+=c[i]/10;   //把十位加到前一位
            c[i]=c[i]%10;      //把个位留在这一位
        }
    }
    while(l>1&&c[l-1]==0)    //去掉前面的0
    l--;
    reverse(c,c+l-1);
    if((n1&&n2)||((!n1)&&(!n2)))    //加负号
    for(i=0;i<l;i++)
    b[i]=c[i]+'0';
    else if((n1&&(!n2))||((!n1)&&n2))
    {
        b[0]='-';
        for(i=1,j=0;i<l+1&&j<l;i++,j++)
        b[i]=c[j]+'0';
    }
    return b;
}
char *chu(int (*a1)[MAX],int (*a2)[MAX],int l1,int l2,int n1,int n2)
{
    int i,j=0,l=l1-l2+1,c[MAX]={0};    //l是得数的最大位数
    char c1[MAX]={0},c2[MAX]={0};
    static char b[2*MAX]={0};
    for(i=0;i<l1;i++)
    c1[i]=(*a1)[l1-1-i]+'0';
    for(i=0;i<l2;i++)
    c2[i]=(*a2)[l2-1-i]+'0';
    if((compare(c1,c2,l1,l2)<0||(*a1)[l1-1]==0)&&(*a2)[l2-1]!=0)
    {
        b[0]='0';
        return b;
    }
    else if((*a2)[l2-1]==0)
    {
        static char p[2*MAX]="不能除以0";
        return p;
    }
    for(i=l2-1;i>=0;i--)      //把除数补上0，可以减少很多循环次数
    (*a2)[i+l-1]=(*a2)[i];
    for(i=0;i<l-1;i++)
    (*a2)[i]=0;
    for(i=l2;i<l1;i++)
    c2[i]=(*a2)[l1-1-i]+'0';
    l2=l1;
    for(i=0;i<l;i++)
    {
        while(compare(c1,c2,l1,l2)>=0)    //如果可以减就继续减
        {
            jian1(&(*a1),&(*a2),&l1,l2);
            c[l-i-1]++;
            memset(c1,0,sizeof(c1));
            for(j=0;j<l1;j++)
            c1[j]=(*a1)[l1-1-j]+'0';
        }
        if(compare(c1,c2,l1,l2)<0&&(*a2)[0]==0)    //如果被除数小了就把除数去掉一个0
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
    while(l>1&&c[l-1]==0)    //去掉前面的0
    l--;
    reverse(c,c+l-1);
    if((n1&&n2)||((!n1)&&(!n2)))
    for(i=0;i<l;i++)
    b[i]=c[i]+'0';
    else if((n1&&(!n2))||((!n1)&&n2))
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
        int temp=*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
}
int judge(char c1[])
{
    if(c1[0]=='-')
    return 0;
    return 1;
}
int compare(char c1[],char c2[],int l1,int l2)
{
    if(l1<l2)
    return -1;
    else if(l1>l2)
    return 1;
    return strcmp(c1,c2);
}
void jian1(int (*a1)[MAX],int (*a2)[MAX],int* l1,int l2)
{
    int i;
    for(i=0;i<*l1;i++)
    {
        if((*a1)[i]<(*a2)[i])
        {
            (*a1)[i]=10+(*a1)[i]-(*a2)[i];    //类似于大数减法，不过需要更改被除数
            (*a1)[i+1]=(*a1)[i+1]-1;
        }
        else
        (*a1)[i]=(*a1)[i]-(*a2)[i];
    }
    for(i=*l1-1;i>=0;i--)    //减完之后再判断被除数的位数
    {
        if((*a1)[i])
        break;
        else
        (*l1)--;
    }
}
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