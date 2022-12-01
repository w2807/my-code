#include<stdio.h>
#include<string.h>
int main()
{
    char *p[4]={"12","34","56","78"};
    char a[10]={0};
    strcpy(a,p[0]);
    strcpy(p[0],p[1]);
    strcpy(p[1],a);
    printf("%s\n",p[0]);
    printf("%s",p[1]);
    return 0;
}