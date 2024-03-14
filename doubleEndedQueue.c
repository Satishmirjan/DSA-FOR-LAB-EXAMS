#include<stdio.h>
#include<stdlib.h>

// Structure to represent a queue
struct queue {
    int* a;    // Array to store elements of the queue
    int front; // Front of the queue
    int rear;  // Rear of the queue
} q;

int size; // Size of the queue



// Function to enqueue an element at the rear of the queue
void renqueue() {
    int item, i;
    printf("Enter element to enqueue: ");
    scanf("%d", &item);

    // Check if the queue is full and reallocate memory if necessary
    if (q.rear == size - 1) {
        printf("Queue is full, reallocating memory...\n");
        size++;
        q.a = (int*)realloc(q.a, size * sizeof(int));
    }

    // If queue is empty, set front and rear to 0 and insert the element
    if (q.front == -1) {
        q.front = 0;
        q.rear = 0;
        *(q.a + q.rear) = item;
        return;
    }

    // Increment rear and insert the element
    q.rear++;
    *(q.a + q.rear) = item;
}

// Function to enqueue an element at the front of the queue
void fenqueue() {
    int item, i;
    printf("Enter element to enqueue: ");
    scanf("%d", &item);

    // Check if the queue is full and reallocate memory if necessary
    if (q.front == 0 && q.rear == size - 1) {
        printf("Queue is full, reallocating memory...\n");
        size++;
        q.a = (int*)realloc(q.a, size * sizeof(int));
    }

    // If queue is empty, set front and rear to 0 and insert the element
    if (q.front == -1) {
        q.front = 0;
        q.rear = 0;
        *(q.a + q.rear) = item;
        return;
    }

    // If front is at the beginning, shift elements to make space for the new element
    if (q.front == 0) {
        for (i = q.rear; i >= 0; i--) {
            *(q.a + i + 1) = *(q.a + i);
        }
        // Insert the element at the front
        *(q.a + 0) = item;
        q.rear++;
        return;
    } else {
        // Decrement front and insert the element
        q.front--;
        *(q.a + q.front) = item;
    }
}

// Function to dequeue an element from the front of the queue
void fdequeue() {
    // Check if the queue is empty
    if (q.front == -1) {
        printf("Queue is empty\n");
        return;
    }

    // Print the dequeued element and update front
    printf("Dequeued element: %d\n", *(q.a + q.front));

    // If queue has only one element, set front and rear to -1
    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        // Increment front
        q.front++;
    }
}

// Function to dequeue an element from the rear of the queue
void rdequeue() {
    // Check if the queue is empty
    if (q.rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    // Print the dequeued element and update rear
    printf("Dequeued element: %d\n", *(q.a + q.rear));

    // If queue has only one element, set front and rear to -1
    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        // Decrement rear
        q.rear--;
    }
}

// Function to display the elements of the queue
void display() {
    // Check if the queue is empty
    if (q.front == -1) {
        printf("Queue is empty\n");
        return;
    }

    // Print the elements of the queue
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
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    q.a = (int*)malloc(size * sizeof(int));

    printf("Menu:\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                fenqueue();
                display();
                break;
            case 2:
                renqueue();
                display();
                break;
            case 3:
                fdequeue();
                display();
                break;
            case 4:
                rdequeue();
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
    }
}
