#include<stdio.h>
#include<string.h>
#include<malloc.h>
void delete(char *a,char *b);
int main()
{
    char *c1,*c2;
    c1=(char*)malloc(100);
    c2=(char*)malloc(100);
    printf("input two strings:");
    gets(c1);
    gets(c2);
    delete(c1,c2);
    puts(c1);
    return 0;
}
void delete(char *a,char *b)
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
    if(!k)
    return;
    i=0;
    j=0;
    while(i<strlen(a))
    {
        if(a[i]!=b[0])
        i++;
        else
        break;
    }
    for(j=i+strlen(b);j<strlen(a);j++)
    {
        a[i]=a[j];
        i++;
    }
    a[i]='\0';
    delete(a,b);
}    