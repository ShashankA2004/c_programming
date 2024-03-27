#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} CircularQueue;

void enqueue(CircularQueue *cq, int value);
int dequeue(CircularQueue *cq);
void display(CircularQueue *cq);

int main()
{
    CircularQueue cq;
    cq.front = -1;
    cq.rear = -1;

    int choice, value;
    do
    {
        printf("\nCircular Queue Operations Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&cq, value);
            break;
        case 2:
            printf("Dequeued element: %d\n", dequeue(&cq));
            break;
        case 3:
            printf("Circular Queue elements: ");
            display(&cq);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void enqueue(CircularQueue *cq, int value)
{
    if (((cq->rear + 1) %  MAX_SIZE) == cq->front)
    {
        printf("Circular Queue is full\n");
        return;
    }
    if (cq->front == -1)
    {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % MAX_SIZE;
    cq->items[cq->rear] = value;
}

int dequeue(CircularQueue *cq)
{
    if (cq->front == -1)
    {
        printf("Circular Queue is empty\n");
        return -1;
    }
    int item = cq->items[cq->front];
    if (cq->front == cq->rear)
    {
        cq->front = cq->rear = -1;
    }
    else
    {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }
    return item;
}

void display(CircularQueue *cq)
{
    if (cq->front == -1)
    {
        printf("Circular Queue is empty\n");
        return;
    }
    int i = cq->front;
    while (i != cq->rear)
    {
        printf("%d ", cq->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", cq->items[i]);
}

