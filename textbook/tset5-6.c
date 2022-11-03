#include<stdio.h>
#include<math.h>
double a,b,c,d;
void f1(double j);
void f2(double j);
void f3(double j);
int main()
{
    printf("input a,b,c:");
    scanf("%lf,%lf,%lf",&a,&b,&c);
    if(b*b-4*a*c>0)
    {
        d=b*b-4*a*c;
        f1(d);
    }
    else if(b*b-4*a*c==0)
    {
        d=0;
        f2(d);
    }
    else
    {
        d=b*b-4*a*c;
        f3(d);
    }
    return 0;
}
void f1(double j)
{
    double x1,x2;
    x1=(-b+d)/(2*a);
    x2=(-b-d)/(2*a);
    printf("x1=%lf,x2=%lf\n",x1,x2);
}
void f2(double j)
{
    double x;
    x=(-b)/(2*a);
    printf("one solution:%lf\n",x);
}
void f3(double j)
{
    double m,n;
    m=(-b)/(2*a);
    n=sqrt(-d);
    printf("x1=%lf+%lfi,x2=%lf-%lfi",m,n,m,n);
}