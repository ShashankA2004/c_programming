#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure representing a queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function prototypes
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void display(Queue *q);

int main() {
    // Initialize the queue
    Queue q;
    q.front = -1;
    q.rear = -1;

    // Variable to store user choice
    int choice, value;

    do {
        // Display menu
        printf("\nQueue Operations Menu\n");

        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue(&q));
                break;
            case 3:
                printf("Queue elements: ");
                display(&q);
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

// Function to enqueue an element into the queue
void enqueue(Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Function to display the elements of the queue
void display(Queue *q) {
    int i;
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

