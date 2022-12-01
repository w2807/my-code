#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i;
    char **p,*name[2]={"1234567","abcdefgh"};
    printf("两个字符串是:\n");
    for(p=name;p<name+2;p++)
    printf("%s\n",*p);
    printf("还是两个字符串:\n");
    for(p=name;p<name+2;p++)
    {
        for(i=0;i<strlen(*p);i++)
        printf("%c",*(*p+i));
        printf("\n");
    }
    return 0;
}