#include <stdio.h>

int main()
{
    struct space
    {
        int x;int y;int z;
    }m[3] = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
    struct space *p1 = m, (*p2)[3] = m;
    printf("%d\n", ++p1->x);
    printf("%d\n", p1 == p2);
    printf("%d\n", (*p2)->x);
    printf("%d\n", (++p1)->x);
    printf("%d\n", (++p1)->y);
    return 0;
}