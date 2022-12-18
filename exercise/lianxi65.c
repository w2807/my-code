#include<stdio.h>
#include<string.h>
int judge(char c1[],char c2[],int l1,int l2)
{
    if(l1<l2)
    return -1;
    if(l1>l2)
    return 1;
    return strcmp(c1,c2);
}
int main()
{
    char s1[1000]={0},s2[1000]={0};
    while(~scanf("%s %s",s1,s2))
    printf("%d\n",judge(s1,s2,strlen(s1),strlen(s2)));
    return 0;
}