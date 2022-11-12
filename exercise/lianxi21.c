#include<stdio.h>
#include<string.h>
#include<malloc.h>
void f(char *a,char *b)
{
    int i=0,j=0,k;
    while(i<strlen(a)&&j<strlen(b))
    {
        if(a[i]==b[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
            j=0;
        }
    }
    if(j==strlen(b))
    k=1;
    else
    k=0;
    if(k)
    printf("yes");
    else
    printf("no");
}
int main()
{
    char *a,*b;
    a=(char*)malloc(100);
    b=(char*)malloc(100);
    printf("input two strings:");
    gets(a);
    gets(b);
    f(a,b);
    return 0;
}