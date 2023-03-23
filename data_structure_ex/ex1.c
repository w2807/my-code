#include <stdio.h>

int sum(int n);

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The sum is %d\n", sum(n));
    return 0;
}

int sum(int n)
{
    int sum = 0, fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
        sum += fact;
    }
    return sum;
}