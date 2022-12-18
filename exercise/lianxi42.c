#include<stdio.h>
struct date
{
    int year,month,day;
};
struct date mingtian(struct date d1);
int main()
{
    struct date d1,d2;
    printf("input a date:");
    scanf("%d.%d.%d",&d1.year,&d1.month,&d1.day);
    d2=mingtian(d1);
    printf("%d.%d.%d",d2.year,d2.month,d2.day);
    return 0;
}
struct date mingtian(struct date d1)
{
    struct date d2;
    d2.day=d1.day+1;
    d2.month=d1.month;
    d2.year=d1.year;
    if(((d1.year%4==0)&&(d1.year%100!=0))||d1.year%400==0)
    {
        if(d1.month==1||d1.month==3||d1.month==5||d1.month==7||d1.month==8||d1.month==10)
        {
            if(d2.day==32)
            {
                d2.day=1;
                d2.month++;
            }
        }
        else if(d1.month==2)
        {
            if(d2.day==30)
            {
                d2.day=1;
                d2.month++;
            }
        }
        else if(d1.month==12)
        {
            if(d2.day==32)
            {
                d2.day=1;
                d2.month=1;
                d2.year++;
            }
        }
        else
        {
            if(d2.day==31)
            {
                d2.day=1;
                d2.month++;
            }
        }
    }
    else
    {
        if(d1.month==1||d1.month==3||d1.month==5||d1.month==7||d1.month==8||d1.month==10)
        {
            if(d2.day==32)
            {
                d2.day=1;
                d2.month++;
            }
        }
        else if(d1.month==2)
        {
            if(d2.day==29)
            {
                d2.day=1;
                d2.month++;
            }
        }
        else if(d1.month==12)
        {
            if(d2.day==32)
            {
                d2.day=1;
                d2.month=1;
                d2.year++;
            }
        }
        else
        {
            if(d2.day==31)
            {
                d2.day=1;
                d2.month++;
            }
        }
    }
    return d2;
}