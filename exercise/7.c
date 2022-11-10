#include<stdio.h>
void delete(char a[]);
int main()
{
    char a[30]={0};
    printf("input a string:");
    gets(a);
    delete(a);
    puts(a);
    return 0;
}
void delete(char a[])
{
    char *p;
    while(*a!='\0')
    {
        if(*a==' ')
        {
            p=a;
            while(*p!='\0')
            {
                *p=*(p+1);
                p++;
            }
        }
        else
        a++;
    }    
}