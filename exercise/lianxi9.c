#include<stdio.h>
#include<stdlib.h>
void jinzhi(int a,int number,char b[])
{
    int i,j,k;
    if(a==2)
    {
        for(i=0;number!=0;i++)
        {
            b[i]='0'+number%2;
            number=number/2;
        }
        b[i]='\0';
        for(j=i;j>=0;j--)
        printf("%c",b[j]);
    }
    if(a==8)
    {
        for(i=0;number!=0;i++)
        {
            b[i]='0'+number%8;
            number=number/8;
        }
        b[i]='\0';
        for(j=i;j>=0;j--)
        printf("%c",b[j]);
    }
    if(a==16)
    {
        for(i=0;number!=0;i++)
        {
            k=number%16;
            if(k>9)
            b[i]='A'+k-10;
            else
            b[i]='0'+k;
            number=number/16;
        }
        b[i]='\0';
        for(j=i;j>=0;j--)
        printf("%c",b[j]);
    }
}
int main()
{
    int a,b;
    char c[100];
    scanf("%d,%d",&a,&b);
    jinzhi(a,b,c);
    return 0;
}