#include<stdio.h>
int main()
{
    char a[4][2][10]={0};
    int i,j;
    for(i=0;i<2;i++)
    for(j=0;j<4;j++)
    scanf("%s",a[j][i]);
    for(i=0;i<2;i++)
    for(j=0;j<4;j++)
    printf("%s ",a[j][i]);
    return 0;
}