#include <stdio.h>

#define N 100

int main(void) {
    int a[N] = {5, 4, 3, 2, 1};
    int b[N] = {6, 4, 3, 2, 1};
    int i;

    for (i = 0; i < N; i++) {
        if (a[i] > b[i]) {
            printf("a is greater than b\n");
            break;
        } else if (a[i] < b[i]) {
            printf("a is less than b\n");
            break;
        }
    }

    if (i == N) {
        printf("a and b are equal\n");
    }

    return 0;
}
