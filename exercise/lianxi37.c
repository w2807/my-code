#include<stdio.h>
#include<stdlib.h>
#define CHOICES 6
int menu(char title[],int max,char (*menu_list)[20]);
int main()
{
    char *greeting="欢迎您的光临！我们今天特别提供：";
    char flavor[CHOICES][20]={"Empty","香草","巧克力","牛奶","脆皮","柠檬"};
    double price[CHOICES]={0.00,1.50,1.80,1.20,2.00,1.80};
    int choice;
    choice=menu(greeting,CHOICES,flavor);
    printf("\n您购买的是：%s口味的冰淇凌\n价格：%.2f元\n",flavor[choice],price[choice]);
    puts("\n谢谢您的光临！欢迎下次再来！\n");
    return 0;
}
int menu(char title[],int max,char (*menu_list)[20])
{
    int choice;
    int n=0;
    printf("\n%s\n",title);
    for(n=0;n<max;++n)
    printf("\t%i.%s\n",n,*(menu_list+n));
    printf("请您选择：");
    for(;;)
    {
        scanf("%i",&choice);
        if(choice>=0&&choice<max)
        break;
        printf("请在0和%i之间选择：",max-1);
    }
    return choice;
}