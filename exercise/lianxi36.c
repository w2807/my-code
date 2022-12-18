#include<stdio.h>
#include<string.h>
void sub(int (*a1)[10],int a2[],int* l1,int l2)
{
    int i;
    for(i=0;i<*l1;i++)
    {
        if((*a1)[i]<a2[i])
        {
            (*a1)[i]=10+(*a1)[i]-a2[i];
            ((*a1)[i+1])--;
        }
        else
        (*a1)[i]=(*a1)[i]-a2[i];
    }
    for(i=0;i<*l1;i++)
    printf("%d ",(*a1)[i]);
    printf("\n");
    for(i=*l1-1;i>=0;i--)
    {
        if((*a1)[i])
        {
            (*l1)=i+1;
            break;
        }
    }
}
int main()
{
    int a1[10]={2,1},a2[10]={3},l1=2,l2=1;
    sub(&a1,a2,&l1,l2);
    printf("%d\n",l1);
    for(int i=0;i<l1;i++)
    printf("%d ",a1[i]);
    return 0;
}