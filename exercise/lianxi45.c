#include<stdio.h>
struct stu
{
    int num,age;
    char name[20],gender[10];
};
int main()
{
    int n,i,j;
    printf("input a number:");
    scanf("%d",&n);
    struct stu ren[n];
    int a[n];
    printf("input the students' message:\n");
    for(i=0;i<n;i++)
    scanf("%d%s%s%d",&ren[i].num,ren[i].name,ren[i].gender,&ren[i].age);
    char c=' ';
    printf("input the numbers:");
    for(i=0;c!='\n';i++)
    {
        scanf("%d",&a[i]);
        c=getchar();
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        if(a[i]==ren[j].num)
        {
            printf("%s %s %d\n",ren[j].name,ren[j].gender,ren[j].age);
            break;
        }
    }
    return 0;
}