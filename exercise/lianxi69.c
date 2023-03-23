#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize);

int main()
{
    int temperatures[] = {43,53,45,32,47,49};
    int returnSize;
    int *returnArray = dailyTemperatures(temperatures, 6, &returnSize);
    for(int i = 0; i < returnSize; i++)
    printf("%d ", returnArray[i]);
    return 0;
}

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    *returnSize = temperaturesSize;
    static int a[100000] = {0}, i;
    for (i = 0; i < temperaturesSize - 1; i++)
    {
        for (int j = 1; j < temperaturesSize - i; j++)
        {
            if (temperatures[i + j] > temperatures[i])
            {
                a[i] = j;
                break;
            }
        }
    }
    a[i] = 0;
    return a;
}