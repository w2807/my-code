#include <stdio.h>
#include <string.h>

void found(char str[]);

int main()
{
    char str[201];
    gets(str);
    while (strcmp(str,"BEGIN") == 0)
    {
        found(str);
        printf("%s\n", str);
        gets(str);
    }
    return 0;
}

void found(char str[])
{
    char plain[27] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
    char strEnd[201];
    if (strcmp(str, "BEGIN") == 0)
    {
        memset(str, 0, strlen(str));
        gets(str);
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] <= 'Z' && str[i] >= 'A')
        str[i] = plain[str[i] - 'A'];
    }
    gets(strEnd);
}