#include<stdio.h>
#include<string.h>
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
int main()
{
    char s1[1000]={0},s2[1000]={0};
    gets(s1);
    gets(s2);
    int l1=strlen(s1),l2=strlen(s2);
    int a1[1000]={0},a2[1000]={0},i,j;
    for(i=0,j=l1-1;i<l1&&j>=0;i++,j--)
    a1[j]=s1[i]-'0';
    for(i=0,j=l2-1;i<l2&&j>=0;i++,j--)
    a2[j]=s2[i]-'0';
    int l=(l1>=l2)?l1:l2;
    if(!judge2(a1,a2,l1,l2))
    {
        int *p1,*p2,tmp;
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
    for(i=0;i<l1;i++)
    printf("%d",a1[i]);
    printf("\n");
    for(i=0;i<l2;i++)
    printf("%d",a2[i]);
    return 0;
}