#include<stdio.h>
#include<stdlib.h>
int main()
{
    double pi=1,i=-1,j=3;
    while((1/j)>=1e-6)
    {
        pi+=1/j*i;
        i=-i;
        j=j+2;
    }
    pi=pi+1/j*i;
    pi*=4;
    printf("%.8f\n",pi);
    return 0;
}