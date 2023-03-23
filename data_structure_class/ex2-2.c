#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node, *List;

List createList(int n);
List cheng(List L1, List L2);
void printList(List L);

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    List L1 = createList(n1), L2 = createList(n2);
}