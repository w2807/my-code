#include<stdio.h>
#include<ctype.h>
int main()
{
    char ch;
    printf("Enter a character:\n");
    ch=getchar();
    if(islower(ch))
    ch=toupper(ch);
    putchar(ch);
    fflush(stdin);
    return 0;
}