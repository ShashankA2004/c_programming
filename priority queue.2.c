#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
typedef struct
{
    int items[MAX_SIZE];
    int priority[MAX_SIZE];
    int front, rear;
} PriorityQueue;

void enqueue(PriorityQueue *pq, int value, int priority);
int dequeue(PriorityQueue *pq);
void display(PriorityQueue *pq);

int main()
{
    PriorityQueue pq;
    pq.front = -1;
    pq.rear = -1;

    int choice, value, priority;

    do
    {
        printf("\nPriority Queue Operations Menu\n");
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
            printf("Enter priority: ");
            scanf("%d", &priority);
            enqueue(&pq, value, priority);
            break;
        case 2:
            printf("Dequeued element: %d\n", dequeue(&pq));
            break;
        case 3:
            printf("Priority Queue elements: ");
            display(&pq);
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

void enqueue(PriorityQueue *pq, int value, int priority)
{
    if (pq->rear == MAX_SIZE - 1)
    {
        printf("Priority Queue is full\n");
        return;
    }
    if (pq->front == -1)
    {
        pq->front = 0;
        pq->rear = 0;
        pq->items[pq->rear] = value;
        pq->priority[pq->rear] = priority;
    }
    else
    {
        int i;
        for (i = pq->rear; i >= pq->front; i--)
        {
            if (priority > pq->priority[i])
            {
                pq->items[i + 1] = pq->items[i];
                pq->priority[i + 1] = pq->priority[i];
            }
            else
            {
                break;
            }
        }
        pq->items[i + 1] = value;
        pq->priority[i + 1] = priority;
        pq->rear++;
    }
}

int dequeue(PriorityQueue *pq)
{
    if (pq->front == -1)
    {
        printf("Priority Queue is empty\n");
        return -1;
    }
    int item = pq->items[pq->front];
    if (pq->front == pq->rear)
    {
        pq->front = pq->rear = -1;
    }
    else
    {
        pq->front++;
    }
    return item;
}

void display(PriorityQueue *pq)
{
    int i;
    if (pq->front == -1)
    {
        printf("Priority Queue is empty\n");
        return;
    }
    for (i = pq->front; i <= pq->rear; i++)
    {
        printf("(%d, %d) ", pq->items[i], pq->priority[i]);
    }
    printf("\n");
}

