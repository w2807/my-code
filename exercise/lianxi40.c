#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<malloc.h>
void xipai(char pai[][10]);
void fapai(char pai[][10]);
int main()
{
    time_t t;
    srand((unsigned)time(&t));
    char pai[52][10]={
	"红桃2","红桃3","红桃4","红桃5","红桃6","红桃7","红桃8","红桃9","红桃10","红桃J","红桃Q","红桃K","红桃A",
	"方块2","方块3","方块4","方块5","方块6","方块7","方块8","方块9","方块10","方块J","方块Q","方块K","方块A",
	"草花2","草花3","草花4","草花5","草花6","草花7","草花8","草花9","草花10","草花J","草花Q","草花K","草花A",		
	"黑桃2","黑桃3","黑桃4","黑桃5","黑桃6","黑桃7","黑桃8","黑桃9","黑桃10","黑桃J","黑桃Q","黑桃K","黑桃A",
	};
    xipai(pai);
    fapai(pai);
    return 0;
}
void xipai(char pai[][10])
{
    int i,j;
    int n;
    char *a=(char*)malloc(10);
    for(n=0;n<52;n++)
    {
        i=rand()%52;
        j=rand()%52;
        strcpy(a,pai[i]);
        strcpy(pai[i],pai[j]);
        strcpy(pai[j],a);
    }
}
void fapai(char pai[][10])
{
    int i,j=0,k;
    for(i=1;i<=4;i++)
    {
        printf("第%d堆：",i);
        j+=13;
        if(j<=52)
        {
            for(k=j-13;k<j;k++)
            printf("%s\t",pai[k]);
        }
        printf("\n");
    }
}