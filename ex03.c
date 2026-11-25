
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define A 0.6180339887

typedef struct
{
    int key;
    char val[30];
    int used;
} Entry;

Entry table[SIZE];

int h_div(int k)
{
    return ((k % SIZE) + SIZE) % SIZE;
}

int h_mul(int k)
{
    double x = k * A;
    double f = x - (int)x;

    return (int)(SIZE * f);
}

void insert(int k, char *v, int mul)
{
    int i = mul ? h_mul(k) : h_div(k);
    int start = i;

    while (table[i].used)
    {
        if (table[i].key == k)
        {
            printf("Key already exists.\n");
            return;
        }

        i = (i + 1) % SIZE;

        if (i == start)
        {
            printf("Hash table is full.\n");
            return;
        }
    }

    table[i].key = k;
    strcpy(table[i].val, v);
    table[i].used = 1;

    printf("Inserted successfully.\n");
}

char *search(int k, int mul)
{
    int i = mul ? h_mul(k) : h_div(k);
    int start = i;

    while (table[i].used)
    {
        if (table[i].key == k)
        {
            return table[i].val;
        }

        i = (i + 1) % SIZE;

        if (i == start)
        {
            break;
        }
    }

    return NULL;
}

void display()
{
    printf("\nIndex\tKey\tValue\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (table[i].used)
        {
            printf("%d\t%d\t%s\n",
                   i, table[i].key, table[i].val);
        }
        else
        {
            printf("%d\t--------\n", i);
        }
    }
}

int main()
{
    int choice, k, method;
    char v[30];

    printf("Method? 1 = Division, 2 = Multiplication: ");
    scanf("%d", &method);

    if (method != 1 && method != 2)
    {
        printf("Invalid hashing method.\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        table[i].used = 0;
    }

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Key: ");
            scanf("%d", &k);

            printf("Value: ");
            scanf("%29s", v);

            insert(k, v, method == 2);
        }
        else if (choice == 2)
        {
            char *res;

            printf("Key: ");
            scanf("%d", &k);

            res = search(k, method == 2);

            if (res != NULL)
            {
                printf("Found: %s\n", res);
            }
            else
            {
                printf("Not found.\n");
            }
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
