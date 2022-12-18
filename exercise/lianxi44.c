#include<stdio.h>
struct date
{
    int year,month,day;
};
struct date riqi(int year,int n);
int main()
{
    int year,n;
    printf("input a year and a number:");
    scanf("%d%d",&year,&n);
    struct date d;
    d=riqi(year,n);
    printf("%d.%d.%d",d.year,d.month,d.day);
    return 0;    
}
struct date riqi(int year,int n)
{
    int day[12]={31,28,31,30,31,30,31,31,30,31,30,31},i=0,j=0;
    struct date d;
    d.year=year;
    if((year%4==0&&year%100!=0)||year%400==0)
    {
        day[1]=29;
        while(i<12)
        {
            j+=day[i];
            i++;
            if(n<=j)
            break;
        }
        d.day=day[i-1]-j+n;
        d.month=i;
    }
    else
    {
        while(i<12)
        {
            j+=day[i];
            i++;
            if(n<=j)
            break;
        }
        d.day=day[i-1]-j+n;
        d.month=i;
    }
    return d;
}