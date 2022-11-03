#include<stdio.h>
#include<stdlib.h>
int main()
{
    int letter=0,space=0,number=0,other=0;
    char c;
    printf("输入字符，以回车键结束\n");
    for(;c!='\n';)
    {
        c=getchar();
        if((c<='z'&&c>='a')||(c<='Z'&&c>='A'))
        letter+=1;
        else if(c==' ')
        space+=1;
        else if(c<='9'&&c>='0')
        number+=1;
        else other+=1;
    }
    other-=1;
    printf("letter=%d,space=%d,number=%d,other=%d\n",letter,space,number,other);
    return 0;
}