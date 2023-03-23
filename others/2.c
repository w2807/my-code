#include <stdio.h>
#include <string.h>

int isValid(char *s);

int main()
{
    char s[20];
    while (~scanf("%s", s))
    {
        printf("%d\n", isValid(s));
    }
    return 0;
}

int isValid(char *s)
{
    char a[20];
    int top = -1;
    for(int i = 0; i < strlen(s) - 1; i++)
    {
        if(s[i] == '(')
        a[i] = ')';
        else if(s[i] == '[')
        a[i] = ']';
        else if(s[i] == '{')
        a[i] = '}';
        top++;
        if(a[top] == s[i + 1])
        a[top--] = '\0';
    }
    if(top == -1)
    return 1;
    return 0;
}