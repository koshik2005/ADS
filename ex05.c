
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    int degree;
    int mark;
    struct Node *parent;
    struct Node *child;
    struct Node *left;
    struct Node *right;
} Node;

Node *min = NULL;

Node *newNode(int key)
{
    Node *n = (Node *)malloc(sizeof(Node));

    if (n == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    n->key = key;
    n->degree = 0;
    n->mark = 0;
    n->parent = NULL;
    n->child = NULL;
    n->left = n;
    n->right = n;

    return n;
}

void insert(int key)
{
    Node *n = newNode(key);

    if (min == NULL)
    {
        min = n;
    }
    else
    {
        n->left = min;
        n->right = min->right;
        min->right->left = n;
        min->right = n;

        if (n->key < min->key)
        {
            min = n;
        }
    }
}

void display()
{
    if (min == NULL)
    {
        printf("Heap empty\n");
        return;
    }

    Node *t = min;

    printf("Root List: ");

    do
    {
        printf("%d ", t->key);
        t = t->right;
    }
    while (t != min);

    printf("\n");
}

int main()
{
    int choice;
    int key;

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Get Min");
        printf("\n4. Exit");
        printf("\nEnter choice: ");

        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter key: ");
            scanf("%d", &key);

            insert(key);
        }
        else if (choice == 2)
        {
            display();
        }
        else if (choice == 3)
        {
            if (min != NULL)
            {
                printf("Minimum = %d\n", min->key);
            }
            else
            {
                printf("Heap empty\n");
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
