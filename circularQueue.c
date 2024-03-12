#include<stdio.h>
#include<stdlib.h>

// Structure to represent a circular queue
struct queue {
    int* a;    // Array to store elements of the queue
    int front; // Front of the queue
    int rear;  // Rear of the queue
} q;

int size; // Size of the circular queue

// Function to enqueue an element into the circular queue
void enqueue() {
    int item, i;
    printf("Enter element to enqueue: ");
    scanf("%d", &item);
    
    // Check if the circular queue is full and reallocate memory if necessary
    if ((q.rear + 1) % size == q.front) {
        printf("Circular queue is full, reallocating memory...\n");
        size++;
        q.a = (int*)realloc(q.a, size * sizeof(int));
    }
    
    // If circular queue is empty, set front and rear to 0 and insert the element
    if (q.front == -1) {
        q.front = q.rear = 0;
        *(q.a + q.rear) = item;
        return;
    }

    // Increment rear in a circular manner and insert the element
    q.rear = (q.rear + 1) % size;
    *(q.a + q.rear) = item;
}

// Function to dequeue an element from the circular queue
void dequeue() {
    // Check if the circular queue is empty
    if (q.front == -1) {
        printf("Circular queue is empty\n");
        return;
    }
    
    // Print the dequeued element and update front
    printf("Dequeued element: %d\n", *(q.a + q.front));
    // If circular queue has only one element, set front and rear to -1
    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        // Increment front in a circular manner
        q.front = (q.front + 1) % size;
    }
}

// Function to display the elements of the circular queue
void display() {
    // Check if the circular queue is empty
    if (q.front == -1) {
        printf("Circular queue is empty\n");
        return;
    }

    // Print the elements of the circular queue
    printf("Circular queue elements: ");
    if (q.front <= q.rear) {
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d ", *(q.a + i));
        }
    } else {
        for (int i = q.front; i < size; i++) {
            printf("%d ", *(q.a + i));
        }
        for (int i = 0; i <= q.rear; i++) {
            printf("%d ", *(q.a + i));
        }
    }
    printf("\n");
}

// Main function
void main() {
    q.front = q.rear = -1;
    int choice;
    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);
    q.a = (int*)malloc(size * sizeof(int));
    printf("Menu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
