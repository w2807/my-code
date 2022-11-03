#include<stdio.h>
#include<stdlib.h>
#define pi 3.1415926
double volume(double a,double b,double c);
int main()
{
    double r1,r2,h,v;
    label:printf("input the two radiuses and the height:");
    scanf("%lf,%lf,%lf",&r1,&r2,&h);
    if(r1==r2)
    {
        printf("illegal input!\n");
        goto label;
    }
    v=volume(r1,r2,h);
    printf("volume=%lf\n",v);
    return 0;
}
double volume(double a,double b,double c)
{
    double v;
    if(a>b)
    {
        v=pi*(a*a-b*b)*c;
        return v;
    }
    else if(a<b)
    {
        v=pi*(b*b-a*a)*c;
        return v;
    }
    return 0;
}