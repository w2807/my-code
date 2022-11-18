#include<stdio.h>
#include<string.h>
int cmp(char *,char *);
int main()
{
    char a[10],b[10];
    printf("input two strings:");
    gets(a);
    gets(b);
    if(cmp(a,b)>0)
    printf("a>b");
    else if(cmp(a,b)==0)
    printf("a=b");
    else 
    printf("a<b");
    return 0; 
}
int cmp(char *p1,char *p2)
{
    int i;
    while(*p1&&*p2)
    {
        if(*p1==*p2)
        {
            i=0;
            p1++;
            p2++;
        }
        else if(*p1>*p2)
        {
            i=1;
            break;
        }
        else 
        {
            i=-1;
            break;
        }
    }
    return i;
}