#include<stdio.h>
struct date
{
    int year,month,day;
};
int tian(struct date d);
int main()
{
    struct date d;
    printf("input a date:");
    scanf("%d.%d.%d",&d.year,&d.month,&d.day);
    printf("%d",tian(d));
    return 0;
}
int tian(struct date d)
{
    int day[12]={31,28,31,30,31,30,31,31,30,31,30,31},i,j=0,k;
    if((d.year%4==0&&d.year%100!=0)||d.year%400==0)
    {
        day[1]=29;
        for(i=0;i<d.month;i++)
        j+=day[i];
        k=j-day[d.month-1]+d.day;
    }
    else
    {
        for(i=0;i<d.month;i++)
        j+=day[i];
        k=j-day[d.month-1]+d.day;
    }
    return k;
}