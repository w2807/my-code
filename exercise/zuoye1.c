#include<stdlib.h>
#include<stdio.h>
int main()
{
    int a,i,j=1;
    float s=0;
    for(a=2;a<=10;a=a+2)
    {
        for(i=1;i<=a;i++)
        j*=i;
        s+=1.0/j;
    }
    printf("%.12f\n",s);
    return 0;
}