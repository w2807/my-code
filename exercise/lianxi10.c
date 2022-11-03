#include<stdio.h>
#include<string.h>
int main()
{
    printf("input a sentence\n");
    int i,n[5]={0};
    char str1[5][10]={"that","and","two","we","the"},str2[30][10]={0};
    int j,k;
    char c=' ';
    for(i=0;c!='\n';i++)
    {
        scanf("%s",str2[i]);
        c=getchar();
    }
    for(j=0;j<5;j++)
    {
        for(k=0;k<30;k++)
        if(strcmp(str1[j],str2[k])==0)
        n[j]++;
    }
    for(i=0,j=0;i<5&&j<5;i++,j++)
    printf("%s:%d\n",str1[i],n[j]); 
    return 0;
}