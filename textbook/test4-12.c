#include<stdio.h>
#include<stdlib.h>
int main()
{
    int day,x1,x2;
    printf("\n求解猴子吃桃子问题\n\n");
    day=9;
    x2=1;
    while(day>0)
    {
        x1=(x2+1)*2;
        x2=x1;
        day--;
    }
    printf("桃子总数=%d\n\n",x1);
    return 0;
}