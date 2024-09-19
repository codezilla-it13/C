#include <stdio.h>
#include <stdlib.h>

struct treenode {
    int element;
    struct treenode *left;
    struct treenode *right;
};

typedef struct treenode *position, *searchtree;

searchtree insert(int x, searchtree t) {
    if (t == NULL) {
        t = (struct treenode*)malloc(sizeof(struct treenode));
        if (t == NULL)
            exit(1);  // Exit if memory allocation fails
        t->element = x;
        t->left = t->right = NULL;
    } else if (x < t->element) {
        t->left = insert(x, t->left);
    } else if (x > t->element) {
        t->right = insert(x, t->right);
    }
    return t;
}

position findmin(searchtree t) {
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findmin(t->left);
}

position findmax(searchtree t) {
    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return findmax(t->right);
}

searchtree remove_node(int x, searchtree t) {
    if (t == NULL) {
        printf("\nElement not found\n");
        return NULL;  // Return NULL if the tree is empty
    }
    
    if (x < t->element) {
        t->left = remove_node(x, t->left);
    } else if (x > t->element) {
        t->right = remove_node(x, t->right);
    } else {
        // Node found
        if (t->left == NULL) {
            position temp = t->right; // Save the right child
            free(t); // Free the current node
            return temp; // Return the right child
        } else if (t->right == NULL) {
            position temp = t->left; // Save the left child
            free(t); // Free the current node
            return temp; // Return the left child
        } else {
            // Node has two children
            position minNode = findmin(t->right);
            t->element = minNode->element; // Copy the min value
            t->right = remove_node(minNode->element, t->right); // Remove min node
        }
    }
    return t;
}

void intrav(searchtree head) {
    if (head == NULL)
        return;
    if(head->left != NULL)
        intrav(head->left);
    printf("%d\t", head->element);
    if(head->right != NULL)
        intrav(head->right);
}

// Main Program
int main() {
    int n, i, dat, ch;
    searchtree t = NULL;
    position node;

    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {  // Changed loop to start from 0
        scanf("%d", &dat);
        t = insert(dat, t);
    }
    printf("Inorder Traversal:\n");
    intrav(t);
    printf("\n****MENU****\n");
    printf("1. Insert a node\n");
    printf("2. Delete a node\n");
    printf("3. Find Minimum\n");
    printf("4. Find Maximum\n");
    printf("5. Display (Inorder Traversal)\n");
    printf("6. Exit\n");
    
    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
                printf("Enter the element to be inserted: ");
                scanf("%d", &dat);
                t = insert(dat, t);
                break;
            case 2:
                if (t == NULL) {
                    printf("Tree is empty, cannot delete.\n");
                } else {
                    printf("Enter the node to be deleted: ");
                    scanf("%d", &dat);
                    t = remove_node(dat, t);
                }
                break;
            case 3:
                node = findmin(t);
                if (node != NULL)
                    printf("The Minimum element is %d\n", node->element);
                else
                    printf("Tree is empty.\n");
                break;
            case 4:
                node = findmax(t);
                if (node != NULL)
                    printf("The Maximum element is %d\n", node->element);
                else
                    printf("Tree is empty.\n");
                break;
            case 5:
                if (t == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Inorder Traversal:\n");
                    intrav(t);
                    printf("\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);  // Loop indefinitely until exit
}
