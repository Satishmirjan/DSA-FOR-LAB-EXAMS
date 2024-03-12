#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the Binary Search Tree
struct node {
    int item;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

// Function to create a new node with the given item
NODE getnode(int X) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->item = X;
    temp->llink = temp->rlink = NULL;
    return temp;
}

// Function to insert a node with the given item into the BST
NODE insert(NODE root, int X) {
    if (root == NULL)
        return getnode(X);
    
    if (X < root->item)
        root->llink = insert(root->llink, X);
    else if (X > root->item)
        root->rlink = insert(root->rlink, X);
    
    return root;
}

// Function to perform in-order traversal of the BST
void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->llink);
        printf("%d ", root->item);
        inorder(root->rlink);
    }
}

// Function to perform pre-order traversal of the BST
void preorder(NODE root) {
    if (root != NULL) {
        printf("%d ", root->item);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

// Function to perform post-order traversal of the BST
void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d ", root->item);
    }
}

// Function to search for a node with the given key in the BST
NODE search(NODE root, int key) {
    if (root == NULL || root->item == key)
        return root;
    
    if (key < root->item)
        return search(root->llink, key);
    else
        return search(root->rlink, key);
}

// Function to find the parent of a node with the given key in the BST
NODE findParent(NODE root, int key) {
    NODE parent = NULL;
    while (root != NULL && root->item != key) {
        parent = root;
        if (key < root->item)
            root = root->llink;
        else
            root = root->rlink;
    }
    return parent;
}

// Function to find the node with the minimum key value in the BST
NODE findMinNode(NODE root) {
    while (root->llink != NULL)
        root = root->llink;
    return root;
}

// Function to delete a node with the given key from the BST
NODE deleteNode(NODE root, int key) {
    if (root == NULL)
        return root;
    
    if (key < root->item)
        root->llink = deleteNode(root->llink, key);
    else if (key > root->item)
        root->rlink = deleteNode(root->rlink, key);
    else {
        // Node with only one child or no child
        if (root->llink == NULL) {
            NODE temp = root->rlink;
            free(root);
            return temp;
        } else if (root->rlink == NULL) {
            NODE temp = root->llink;
            free(root);
            return temp;
        }
        
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        NODE temp = findMinNode(root->rlink);
        
        // Copy the inorder successor's content to this node
        root->item = temp->item;
        
        // Delete the inorder successor
        root->rlink = deleteNode(root->rlink, temp->item);
    }
    return root;
}

// Function to count the number of nodes in the BST
int countNodes(NODE root) {
    if (root == NULL)
    if (root == NULL)
        return -1;
    int leftHeight = height(root->llink);
    int rightHeight = height(root->rlink);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to find the maximum node in the BST
NODE findMaxNode(NODE root) {
    while (root->rlink != NULL)
        root = root->rlink;
    return root;
}

// Function to display the details of a node along with its parent (if exists)
void displayNodeDetails(NODE root, int key, NODE parent) {
    NODE node = search(root, key);
    if (node == NULL) {
        printf("Node with key %d does not exist in the BST\n", key);
        return;
    }
    
    printf("Node details for key %d:\n", key);
    printf("Item: %d\n", node->item);
    if (parent == NULL)
        printf("Parent: None\n");
    else
        printf("Parent: %d\n", parent->item);
}

// Function to search for a node with the given key in the BST and return its parent
NODE searchWithParent(NODE root, int key, NODE parent) {
    if (root == NULL || root->item == key)
        return parent;
    
    if (key < root->item)
        return searchWithParent(root->llink, key, root);
    else
        return searchWithParent(root->rlink, key, root);
}

// Main function
int main() {
    int choice, X, key;
    NODE root = NULL;
    
    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. InOrder Traversal\n");
    printf("3. PreOrder Traversal\n");
    printf("4. PostOrder Traversal\n");
    printf("5. Search Node\n");
    printf("6. Delete Node\n");
    printf("7. Count Nodes\n");
    printf("8. Find Height\n");
    printf("9. Find Maximum Node\n");
    printf("10. Exit\n");
    
    while (1) {
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter an Element: ");
                scanf("%d", &X);
                root = insert(root, X);
                break;
            case 2:
                printf("InOrder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("PreOrder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("PostOrder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                NODE parent = searchWithParent(root, key, NULL);
                displayNodeDetails(root, key, parent);
                break;
            case 6:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 7:
                printf("Number of Nodes in BST: %d\n", countNodes(root));
                break;
            case 8:
                printf("Height of BST: %d\n", height(root));
                break;
            case 9:
                printf("Details of Maximum Node:\n");
                NODE maxNode = findMaxNode(root);
                printf("Item: %d\n", maxNode->item);
                break;
            case 10:
                printf("!!THANK YOU!!\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    
    return 0;
}
