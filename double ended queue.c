#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly ended queue
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Structure to represent the doubly ended queue
struct Deque {
    struct Node *front;
    struct Node *rear;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
       newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the doubly ended queue
void initializeDeque(struct Deque *dq) {
    dq->front = NULL;
    dq->rear = NULL;
}

// Function to check if the doubly ended queue is empty
int isEmpty(struct Deque *dq) {
    return dq->front == NULL;
}

// Function to insert an element at the front of the doubly ended queue
void insertFront(struct Deque *dq, int data) {
    struct Node *newNode = createNode(data);
    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    printf("%d inserted at the front of the deque.\n", data);
}

// Function to insert an element at the rear of the doubly ended queue
void insertRear(struct Deque *dq, int data) {
    struct Node *newNode = createNode(data);
    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        newNode->prev = dq->rear;
        dq->rear = newNode;
    }
    printf("%d inserted at the rear of the deque.\n", data);
}

// Function to delete an element from the front of the doubly ended queue
int deleteFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque underflow. Cannot delete element from front.\n");
        return -1; // Return some invalid value indicating underflow
    }
    int data = dq->front->data;
    struct Node *temp = dq->front;
     if (dq->front == dq->rear) {
        dq->front = dq->rear = NULL;
    } else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }
    free(temp);
    return data;
}

// Function to delete an element from the rear of the doubly ended queue
int deleteRear(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque underflow. Cannot delete element from rear.\n");
        return -1; // Return some invalid value indicating underflow
    }
    int data = dq->rear->data;
    struct Node *temp = dq->rear;
    if (dq->front == dq->rear) {
        dq->front = dq->rear = NULL;
    } else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }
    free(temp);
    return data;
}
// Function to display the elements of the doubly ended queue
void display(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements are: ");
    struct Node *temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Deque dq;
    initializeDeque(&dq);

    int choice, value;
    while (1) {
        // Prompting the user for input
         printf("\nDoubly Ended Queue Operations:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter the value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                value = deleteFront(&dq);
                if (value != -1)
                    printf("Deleted element from front: %d\n", value);
                break;
            case 4:
                value = deleteRear(&dq);
                if (value != -1)
                    printf("Deleted element from rear: %d\n", value);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    }

    return 0;
}

