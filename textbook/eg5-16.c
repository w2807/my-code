#include<stdio.h>
#include<math.h>
#define DEBUG
int main()
{
    double s,t,x;
    int n;
    printf("please input s:");
    scanf("%lf",&x);
    t=x;
    n=1;
    s=x;
    while(fabs(t)>=1e-6)
    {
        n=n+2;
        t=t*(-x*x)/((float)(n)-1)/(float)(n);
        s=s+t;
        #ifdef DEBUG
        printf("this is test data:n=%d,t=%f,s=%f\n",n,t,s);
        #endif
    }
    printf("sin(%f)=%f\n",x,s);
    return 0;
}