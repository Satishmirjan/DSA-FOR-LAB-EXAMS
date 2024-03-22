#include<stdio.h>
#include<stdlib.h>

struct node {
    int item;
    struct node *next;
    struct node *prev;
};
typedef struct node* node;
int n = 0;

// Function to create a new node
node getnode(int val) {
    node temp = (node)malloc(sizeof(struct node));
    temp->prev = temp;
    temp->next = temp;
    temp->item = val;
    return temp;
}

// Function to insert a node at the front of the list
node insertfront(node head, int item) {
    n++;
    node temp = getnode(item);
    if (head == NULL) {
        return temp;
    }
    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return temp;
}

// Function to insert a node at the rear of the list
node insertrear(node head, int item) {
    n++;
    node temp = getnode(item);
    if (head == NULL) {
        return temp;
    }
    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return head;
}

// Function to delete the node at the front of the list
node deletefront(node head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    node cur = head->next;
    cur->prev = head->prev;
    head->prev->next = cur;
    n--;
    if (head == head->next) {
        free(head);
        return NULL;
    }
    free(head);
    return cur;
}

// Function to delete the node at the rear of the list
node deleterear(node head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    node temp = head->prev;
    temp->prev->next = head;
    head->prev = temp->prev;
    n--;
    if (temp == head) {
        free(temp);
        return NULL;
    }
    free(temp);
    return head;
}

// Function to display the elements of the list
void display(node head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node cur = head;
    do {
        printf("%d\t", cur->item);
        cur = cur->next;
    } while (cur != head);
    printf("\n");
}

// Function to insert a node at a specified position in the list
node insertpos(node head, int item, int pos) {
    node temp = getnode(item);
    if (pos < 0 || pos > n + 1) {
        printf("Invalid position\n");
        return head;
    }
    if (pos == 1) {
        return insertfront(head, item);
    }
    if (pos == n + 1) {
        return insertrear(head, item);
    }
    n++;
    node cur = head;
    while (pos != 1) {
        cur = cur->next;
        pos--;
    }
    temp->next = cur;
    temp->prev = cur->prev;
    cur->prev->next = temp;
    cur->prev = temp;
    return head;
}

// Function to delete a node at a specified position in the list
node deletebypos(node head, int pos) {
    if (pos < 0 || pos > n + 1) {
        printf("Invalid position\n");
        return head;
    }
    if (pos == 1) {
        return deletefront(head);
    }
    if (pos == n ) {
        return deleterear(head);
    }
    n--;
    node cur = head;
    while (pos != 1) {
        cur = cur->next;
        pos--;
    }
    node temp;
    temp = cur->prev;
    temp->next = cur->next;
    cur->next->prev = temp;
    free(cur);
    return head;
}

// Function to insert a node in sorted order
node insertbyorder(node head, int item) {
    n++;
    node temp = getnode(item);
    if (head == NULL) {
        return temp;
    }
    node cur = head;
    if (item < cur->item) {
        return insertfront(head, item);
    }
    if (head->prev->item < item) {
        return insertrear(head, item);
    }
    while (item > cur->item) {
        cur = cur->next;
    }
    temp->next = cur;
    temp->prev = cur->prev;
    cur->prev->next = temp;
    cur->prev = temp;
    return head;
}

// Function to search for an element in the list
int search(node head, int item) {
    int pos = 1;
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    node cur = head;
    do {
        if (item == cur->item) {
            return pos;
        }
        cur = cur->next;
        pos++;
    } while (cur != head);
    return -1;
}

// Function to search for an element by position and display it
void searchbypos(node head, int pos) {
    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return;
    }
    node cur = head;
    while (pos != 1) {
        cur = cur->next;
        pos--;
    }
    printf("The element at the given position is %d\n", cur->item);
}

// Main function
void main() {
    node head = NULL;

    int choice, item, pos;
    printf("Menu\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Insert by Position\n6. Delete by Position\n7. Search by Element\n8. Delete by Value\n9. Display\n10. Insert by Order\n11. Search by Position\n12. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                head = insertfront(head, item);
                display(head);
                break;

            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                head = insertrear(head, item);
                display(head);
                break;

            case 3:
                head = deletefront(head);
                display(head);
                break;

            case 4:
                head = deleterear(head);
                display(head);
                break;

            case 5:
                printf("Enter the item and position: ");
                scanf("%d %d", &item, &pos);
                head = insertpos(head, item, pos);
                display(head);
                break;

            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                head = deletebypos(head, pos);
                display(head);
                break;

            case 7:
                printf("Enter the element to be searched: ");
                scanf("%d", &item);
                pos = search(head, item);
                if (pos == -1) {
                    printf("Element not found\n");
                } else {
                    printf("Element found at position: %d\n", pos);
                }
                break;

            case 8:
                printf("Enter the element to be deleted: ");
                scanf("%d", &item);
                pos = search(head, item);
                if (pos == -1) {
                    printf("Element not found\n");
                } else {
                    head = deletebypos(head, pos);
                    printf("Element deleted\n");
                    display(head);
                }
                break;

            case 9:
                display(head);
                break;

            case 10:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                head = insertbyorder(head, item);
                display(head);
                break;

            case 11:
                printf("Enter the position to be searched: ");
                scanf("%d", &pos);
                searchbypos(head, pos);
                break;

            case 12:
                printf("Thank you!\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
