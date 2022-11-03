#include<stdio.h>
#include<stdlib.h>
int main()
{
    double a[5],b,c;
    int i,j;
    printf("input 5 numbers:\n");
    for(j=0;j<5;j++)
    scanf("%lf",&a[j]);
    for(i=0;i<5;i++)
    b+=a[i];
    c=b/5.0;
    printf("average=%f",c);
    return 0;
}