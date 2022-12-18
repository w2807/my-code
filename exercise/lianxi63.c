#include<stdio.h>
#include<string.h>
#include<malloc.h>

char *chu(int a1[], int a2[], int l1, int l2);
void sub(int **a1, int **a2, int* l1, int l2);
void reverse(int *start, int *end);
int judge1(char s[]);
int judge2(char s1[], char s2[], int l1, int l2);

char s1[1000], s2[1000];

int main()
{
    gets(s1);
    gets(s2);
    int a1[1000] = {0}, a2[1000] = {0}, i, j, l1, l2;
    if (!judge1(s1))
    {
        l1 = strlen(s1) - 1;
        for (i = 1, j = l1 - 1; i < l1 + 1 && j >= 0; i++, j--)
            a1[j] = s1[i] - '0';
    }
    else
    {
        l1 = strlen(s1);
        for (i = 0, j = l1 - 1; i < l1 && j >= 0; i++, j--)
            a1[j] = s1[i] - '0';
    }
    if (!judge1(s2))
    {
        l2 = strlen(s2) - 1;
        for (i = 1, j = l2 - 1; i < l2 + 1 && j >= 0; i++, j--)
            a2[j] = s2[i] - '0';
    }
    else
    {
        l2 = strlen(s2);
        for (i = 0, j = l2 - 1; i < l2 && j >= 0; i++, j--)
            a2[j] = s2[i] - '0';
    }
    char *p;
    p = (char*)malloc(2000);
    p = chu(a1, a2, l1, l2);
    puts(p);
    return 0;
}

void sub(int **a1, int **a2, int* l1, int l2)
{
    int i = 0;
    for (i = 0; i < *l1; i++)
    {
        if ((*a1)[i] < (*a2)[i])
        {
            (*a1)[i] = (*a1)[i] - (*a2)[i] + 10;
            (*a1)[i + 1] -= 1;
        }
        else
            (*a1)[i] = (*a1)[i] - (*a2)[i];
    }
    while (*l1 > 1 && (*a1)[*l1 - 1] == 0)
        (*l1)--;
}

char *chu(int a1[], int a2[], int l1, int l2)
{
    if (((judge2(s1, s2, l1, l2) < 0) || a1[l1 - 1] == 0) && a2[l2 - 1] != 0)
        return "0";
    else if (a2[l2 - 1] == 0)
        return "error:can't divided by 0";
    static char b[1000] = {0};
    int i, j = 0, l = l1 - l2;
    for (i = l2 - 1; i >= 0; i--)
        a2[i + l] = a2[i];
    for (i = 0; i < l; i++)
        a2[i] = 0;
    char c1[1000], c2[1000];
    for (i = 0; i < l1; i++)
        c1[i] = a1[l1 - 1 - i] + '0';
    for (i = 0; i < l2; i++)
        c2[i] = a2[l2 - 1 - i] + '0';
    c1[l1] = '\0';
    c2[l2] = '\0';
    while (1)
    {
        int x = 0;
        while (judge2(c1, c2, l1, l2) >= 0)
        {
            sub(&a1, &a2, &l1, l2);
            x++;
            for (i = 0; i < l1; i++)
                c1[i] = a1[l1 - 1 - i] + '0';
            c1[l1] = '\0';
        }
        b[j] = x + '0';
        j++;
        reverse(a2, a2 + l2 - 1);
        l2--;
        for (i = 0; i < l2; i++)
            a2[i] = a2[i + 1];
        a2[l2] = 0;
        reverse(a2, a2 + l2 - 1);
        for (i = 0; i < l2; i++)
            c2[i] = a2[l2 - 1 - i] + '0';
        c2[l2] = '\0';
        if (l2 == 0)
            break;
    }
    b[j] = '\0';
    return b;
}

void reverse(int *start, int *end)
{
    while (start < end)
    {
        int tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}

int judge1(char s[])
{
    if (s[0] == '-')
        return 0;
    return 1;
}

int judge2(char s1[], char s2[], int l1, int l2)
{
    int i;
    char c1[1000],c2[1000];
    strcpy(c1,s1);
    strcpy(c2,s2);
    if(!judge1(c1))
    for(i=0;i<strlen(c1);i++)
    c1[i]=c1[i+1];
    if(!judge1(c2))
    for(i=0;i<strlen(c2);i++)
    c2[i]=c2[i+1];
    if(l1<l2)
    return -1;
    if(l1==l2)
    {
        for(i=l1-1;i>=0;i--)
        {
            if(c1[i]==c2[i])
                continue;
            if(c1[i]>c2[i])
                return 1;
            if(c1[i]<c2[i])
                return -1;
        }
    }
    return 0;
}