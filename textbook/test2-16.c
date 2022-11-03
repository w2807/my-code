#include<stdio.h>
#include<stdlib.h>
#define PI 3.141592
int main()
{
    double r,d,c,s;
    printf("请输入圆的半径：");
    scanf("%lg",&r);
    d=2*r;
    c=2*PI*r;
    s=PI*r*r;
    printf("圆的直径是%g\n圆的周长是%g\n圆的面积是%g\n",d,c,s);
    return 0;
}