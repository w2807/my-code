#include<stdio.h>
void sums(float a[],int n,float *sum1,float *sum2,int *n1,int *n2)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            *sum1+=a[i];
            (*n1)++;
        }
        else
        {
            *sum2+=a[i];
            (*n2)++;
        }
    }
}
int main()
{
    float a[10],s1,s2;
    int a1,a2,i;
    printf("input a array:");
    for(i=0;i<10;i++)
    scanf("%f",&a[i]);
    sums(a,10,&s1,&s2,&a1,&a2);
    printf("sum1 is %f,sum2 is %f,positive number is %d,negative number is %d",s1,s2,a1,a2);
    return 0;
}