#include<stdio.h>
#include<stdlib.h>

struct treenode {
    int element;
    struct treenode *left;
    struct treenode *right;
};

typedef struct treenode *position, *searchtree;

searchtree insert(int x, searchtree t) {
    if (t == NULL) {
        t = (struct treenode *)malloc(sizeof(struct treenode));
        if (t == NULL)
            exit(0);
        else {
            t->element = x;
            t->left = t->right = NULL;
        }
    } else if (x < t->element)
        t->left = insert(x, t->left);
    else if (x > t->element)
        t->right = insert(x, t->right);
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

searchtree rem(int x, searchtree t) {
    position temp;
    if (t == NULL)
        printf("\nElement not found\t");
    else if (x < t->element)
        t->left = rem(x, t->left);
    else if (x > t->element)
        t->right = rem(x, t->right);
    else if (t->left && t->right) {
        temp = findmin(t->right);
        t->element = temp->element;
        t->right = rem(t->element, t->right);
    } else {
        temp = t;
        if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;
        free(temp);
    }
    return t;
}

void intrav(searchtree head) {
    if (head == NULL)
        return;
    if (head->left != NULL)
        intrav(head->left);
    printf("%d\t", head->element);
    if (head->right != NULL)
        intrav(head->right);
}

int main() {
    int n, i, dat, ch;
    searchtree t = NULL;
    position node;
    
    printf("\nEnter the number of elements:\t");
    scanf("%d", &n);
    
    printf("\nEnter the elements:\t");
    for (i = 1; i <= n; i++) {
        scanf("%d", &dat);
        t = insert(dat, t);
    }
    
    intrav(t);
    
    do {
        printf("\n****MENU****\n");
        printf("1->Insert a node \n");
        printf("2->Delete a node \n");
        printf("3->Find Minimum\n");
        printf("4->Find Maximum\n");
        printf("5->Display (Inorder Traversal)\n");
        printf("6->Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("\nEnter the element to be inserted:\t");
                scanf("%d", &dat);
                t = insert(dat, t);
                break;
                
            case 2:
                printf("\nEnter the node to be deleted:\t");
                scanf("%d", &dat);
                t = rem(dat, t);
                break;
                
            case 3:
                node = findmin(t);
                if (node != NULL)
                    printf("\nThe minimum element is %d", node->element);
                else
                    printf("\nThe tree is empty");
                break;
                
            case 4:
                node = findmax(t);
                if (node != NULL)
                    printf("\nThe maximum element is %d", node->element);
                else
                    printf("\nThe tree is empty");
                break;
                
            case 5:
                intrav(t);
                break;
                
            case 6:
                exit(0);
                break;
                
            default:
                printf("\nInvalid choice!");
        }
    } while (ch != 6);
    
    return 0;
}

