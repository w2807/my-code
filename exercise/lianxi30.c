#include<stdio.h>
#include<string.h>
#include<malloc.h>
char *jia(int a1[],int a2[],int l1,int l2);
void reverse(int *strat,int *end);
int main()
{
    char s1[1000]={0},s2[1000]={0};
    gets(s1);
    gets(s2);
    int a1[1000]={0},a2[1000]={0},i,j,l1=strlen(s1),l2=strlen(s2);
    for(i=0,j=l1-1;i<l1&&j>=0;i++,j--)
    a1[j]=s1[i]-'0';
    for(i=0,j=l2-1;i<l2&&j>=0;i++,j--) 
    a2[j]=s2[i]-'0';
    for(i=0;i<l1;i++)
    printf("%d",a1[i]);
    printf("\n");
    for(i=0;i<l2;i++)
    printf("%d",a2[i]);
    char *p;
    p=(char*)malloc(2000);
    p=jia(a1,a2,l1,l2);
    printf("\n");
    printf("%d %d\n",9%10,(9/10)%10);
    puts(p);
    return 0;
}
char *jia(int a1[],int a2[],int l1,int l2)
{
    int c[2000]={0};
    static char b[2000]={0};
    int i=0,j=0,l;
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