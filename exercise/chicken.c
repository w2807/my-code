#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c;
    for(a=0;a<100;a=a+1)
    {
        for(b=0;b<100;b=b+1)
        {
            c=100-a-b;
            if(c%3==0)
            {
                if(100==5*a+3*b+c/3)
                printf("%d,%d,%d\n",a,b,c);
            }
        }
    }
    return 0;
}