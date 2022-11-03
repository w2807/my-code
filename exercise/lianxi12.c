#include<stdio.h>
#include<string.h>
void fan(char a[])
{
    int b=strlen(a),i;
    for(i=b;i>=0;i--)
    printf("%c",a[i]);
}
int main()
{
    char a[10];
    printf("input a string:");
    gets(a);
    fan(a);
    return 0;
}