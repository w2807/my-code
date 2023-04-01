#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef struct node
{
    int data;
    struct node *next;
} Node, *List;
typedef struct node1
{
    List front;
    List rear;
} QheadNode;

List creatStack();
QheadNode * creatQueue();
void printStack(List L);
void printQueue(QheadNode * L);
void inputCar(List parklot, QheadNode * waitlot, int car);
List pushStack(List lot, int car);
QheadNode * pushQueue(QheadNode * lot, int car);
int popStack(List lot);
int popQueue(QheadNode * lot);
void outputCar(List parklot, QheadNode * waitlot, List temp, int car);

int main()
{
    List parklot = creatStack(), temp = creatStack();
    QheadNode * waitlot = creatQueue();
    int car;
    printf("input the car:");
    while (scanf("%d", &car) == 1)
    {
        inputCar(parklot, waitlot, car);
        printf("input another car, if you don't want to input, press CTRL+Z:");
    }
    printf("output a car:");
    while (scanf("%d", &car) == 1)
    {
        outputCar(parklot, waitlot, temp, car);
        printf("output another car, if you don't want to output, press CTRL+Z:");
    }
    system("pause");
    return 0;
}

List creatStack()
{
    List L = (List)malloc(sizeof(Node));
    L->next = NULL;
    return L;
}
QheadNode * creatQueue()
{
    QheadNode * L = (QheadNode *)malloc(sizeof(QheadNode));
    L->front = NULL;
    L->rear = NULL;
    return L;
}
void printStack(List L)
{
    List p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void printQueue(QheadNode * L)
{
    List p = L->front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void inputCar(List parklot, QheadNode * waitlot, int car)
{
    List p = parklot->next;
    int count = 0;
    while (p)
    {
        p = p->next;
        count++;
    }
    if (count < N)
    {
        pushStack(parklot, car);
        printf("the parking lot is\n");
        printStack(parklot);
    }
    else
    {
        pushQueue(waitlot, car);
        printf("the waiting lot is\n");
        printQueue(waitlot);
    }
}
List pushStack(List lot, int car)
{
    List p;
    p = (List)malloc(sizeof(Node));
    p->data = car;
    p->next = lot->next;
    lot->next = p;
    return lot;
}
QheadNode * pushQueue(QheadNode * lot, int car)
{
    List p;
    p = (List)malloc(sizeof(Node));
    p->data = car;
    p->next = NULL;
    if (lot->rear == NULL)
    {
        lot->front = p;
        lot->rear = p;
    }
    else
    {
        lot->rear->next = p;
        lot->rear = p;
    }
    return lot;
}
int popStack(List lot)
{
    List p = lot->next;
    int outCar;
    outCar = p->data;
    lot->next = p->next;
    free(p);
    return outCar;
}
int popQueue(QheadNode * lot)
{
    List p;
    int outCar;
    p = lot->front;
    if (lot->front == lot->rear)
    {
        lot->front = NULL;
        lot->rear = NULL;
    }
    else
        lot->front = p->next;
    outCar = p->data;
    free(p);
    return outCar;
}
void outputCar(List parklot, QheadNode * waitlot, List temp, int car)
{
    int index = 1, count = 0;
    List p = parklot->next;
    while (p->data != car)
    {
        p = p->next;
        index++;
    }
    if (index != 1)
    {
        for (int i = 1; i < index; i++)
        {
            int outCar;
            outCar = popStack(parklot);
            pushStack(temp, outCar);
        }
        printf("the temp is \n");
        printStack(temp);
        int outCar = popStack(parklot);
        printf("the out car is %d\n", outCar);
        for (int i = 1; i < index; i++)
        {
            int outCar;
            outCar = popStack(temp);
            pushStack(parklot, outCar);
        }
    }
    else
    {
        int outCar;
        outCar = popStack(parklot);
        printf("the car out is %d\n", outCar);
    }
    List p1 = waitlot->front;
    while (p1)
    {
        p1 = p1->next;
        count++;
    }
    printf("the cost is %d\n", index + count);
    if (waitlot->rear != NULL)
    {
        int outCar;
        outCar = popQueue(waitlot);
        pushStack(parklot, outCar);
    }
    printf("the parking lot is\n");
    printStack(parklot);
    printf("the waiting lot is\n");
    printQueue(waitlot);
}