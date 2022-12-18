#include<stdio.h>
struct zhigong
{
    char name[20];
    int gongzi1,gongzi2,zhichu;
};
int main()
{
    int n;
    printf("input a number:");
    scanf("%d",&n);
    struct zhigong ren[n];
    int i;
    for(i=0;i<n;i++)
    scanf("%s%d%d%d",ren[i].name,&ren[i].gongzi1,&ren[i].gongzi2,&ren[i].zhichu);
    for(i=0;i<n;i++)
    printf("%s %.2f\n",ren[i].name,((float)ren[i].gongzi1+(float)ren[i].gongzi2-(float)ren[i].zhichu));
    return 0;
}