#include<stdio.h>
#include<stdlib.h>
int main()
{
    double a[100],b,c;
    int i,j;
    char k;
    printf("input numbers,end with an enter:");
    for(i=0;(k=getchar())!='\n';i++)
    scanf("%lf",&a[i]);
    for(j=0;j<=i;j++)
    b+=a[j];
    c=b/(double)i;
    printf("average=%f",c);
    return 0;
}       