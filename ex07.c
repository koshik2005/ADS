
#include <stdio.h>

#define SIZE 20

int q[SIZE];
int front = 0;
int rear = 0;

void enqueue(int v)
{
    q[rear++] = v;
}

int dequeue()
{
    return q[front++];
}

int isEmpty()
{
    return front == rear;
}

int main()
{
    int n;
    int adj[20][20];
    int visited[20] = {0};
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > SIZE)
    {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter start vertex (0-%d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid start vertex.\n");
        return 1;
    }

    printf("BFS Traversal: ");

    visited[start] = 1;
    enqueue(start);

    while (!isEmpty())
    {
        int v = dequeue();

        printf("%d ", v);

        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }

    return 0;
}
