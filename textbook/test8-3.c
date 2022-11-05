#include<stdio.h>
#define Z 3
int main()
{
    char square[Z][Z];
    char *start=&square[0][0];
    char *end=&square[Z-1][Z-1];
    char *p;
    for(p=end;p>=start;p-=2)
    *p='1';
    for(p=start;p<end;++p)
    {
        ++p;
        *p='0';
    }
    for(p=start;p<=end;++p)
    printf("%3c",*p);
    puts("\n");
    return 0;
}