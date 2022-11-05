#include<stdio.h>
#include<string.h>
#define N 2
void chazhao(char a);
char a[4][N][10];
int main()
{
    char c;
    int i,j;
    for(i=0;i<N;i++)
    {
        printf("输入信息:");
        for(j=0;j<4;j++)
        scanf("%s",a[j][i]);
    }
    printf("查几号?");
    getchar();
    chazhao(c=getchar());
    return 0;
}
void chazhao(char b)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        if(i==b-'1')
        {
            for(j=0;j<4;j++)
            printf("%s ",a[j][i]);
            return;
        }
    }
    printf("没查到");
}