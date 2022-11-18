#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAX 100
char *jia(int a1[],int a2[]);
char *jian(int a1[],int a2[]);
char *cheng(int a1[],int a2[]);
char *chu(int a1[],int a2[]);
int main()
{
    char str1[MAX],str2[MAX],a[2*MAX],*p1;
    p1=(char*)malloc(2*MAX);
    printf("输入两个整数:");
    gets(str1);
    gets(str2);
    int l1=strlen(str1),l2=strlen(str2),i,j,a1[MAX],a2[MAX];
    for(j=0;j<l1;j++)    //将输入的字符串转移到整型数组，方便算
    a[j]=str1[j]-'0';
    for(j=0;j<l2;j++)
    a[j]=str2[j]-'0';
    printf("选择运算类型(1加法,2减法,3乘法,4除法)");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
        {
            p1=jia(a1,a2);
            strcpy(a,p1);
            break;
        }
        case 2:
        {
            p1=jian(a1,a2);
            strcpy(a,p1);
            break;
        }
        case 3:
        {
            p1=cheng(a1,a2);
            strcpy(a,p1);
            break;
        }
        case 4:
        {
            p1=chu(a1,a2);
            strcpy(a,p1);
            break;
        }
    }
    printf("运算结果为:");
    puts(a);
    return 0;
}
char *jia(int a1[],int a2[])
{

}
char *jian(int a1[],int a2[])
{

}
char *cheng(int a1[],int a2[])
{

}
char *chu(int a1[],int a2[])
{

}