#include<stdio.h>
#include<stdlib.h>

// Structure to represent a queue
struct queue {
    int* a;    // Array to store elements of the queue
    int front; // Front of the queue
    int rear;  // Rear of the queue
} q;

int size; // Size of the queue

// Function to determine priority for element insertion based on value
int priority(int num) {
    int i = 0;
    while (i <= q.rear && *(q.a + i) < num) {
        i++;
    }
    return i;
}

// Function to enqueue an element into the queue
void enqueue() {
    int item, i;
    printf("Enter element: ");
    scanf("%d", &item);
    
    // Check if queue is full and reallocate memory if necessary
    if (q.rear == size - 1) {
        printf("Queue full, reallocating memory...\n");
        size++;
        q.a = (int*)realloc(q.a, size * sizeof(int));
    }
    
    // If queue is empty, insert element at front
    if (q.front == -1) {
        q.front = 0;
        q.rear = 0;
        *(q.a + q.rear) = item;
        return;
    }

    // Determine insertion position based on priority
    int pos = priority(item);
    for (i = q.rear; i >= pos; i--) {
        *(q.a + i + 1) = *(q.a + i);
    }
    *(q.a + i + 1) = item;
    q.rear++;
}

// Function to dequeue an element from the queue
void dequeue() {
    // Check if queue is empty
    if (q.rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    
    // If queue has only one element
    if (q.rear == q.front) {
        printf("%d dequeued\n", *(q.a + q.front));
        q.front = q.rear = -1;
        return;
    } else {
        printf("%d dequeued\n", *(q.a + q.front));
        q.front++;
    }
}

// Function to display the elements of the queue
void display() {
    // Check if queue is empty
    if (q.rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    
    // Display elements of the queue
    printf("Queue elements: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", *(q.a + i));
    }
    printf("\n");
}

// Main function
void main() {
    q.front = q.rear = -1;
    int choice;
    
    // Get the size of the queue
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    
    // Allocate memory for the queue
    q.a = (int*)malloc(size * sizeof(int));
    
    // Menu-driven loop
    while (1) {
        // Display menu
        printf("\nMenu\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Perform operation based on user's choice
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thank you\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
