#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    srand((unsigned)time(NULL));
    char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    while(1)
    {
        if((rand()%3)>1)
        printf("%d\n",rand());
        else
        printf("%c ",a[rand()%25]);
    }
    return 0;
}