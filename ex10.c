
#include <stdio.h>

#define MAX 20

typedef struct
{
    int u;
    int v;
    int w;
} Edge;

int find(int parent[], int i)
{
    if (parent[i] == i)
    {
        return i;
    }

    return parent[i] = find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y)
{
    parent[y] = x;
}

int main()
{
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    if (n <= 0 || n > MAX || e < 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    Edge edges[e];

    printf("Enter edges (u v w):\n");

    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);

        if (edges[i].u < 0 || edges[i].u >= n ||
            edges[i].v < 0 || edges[i].v >= n)
        {
            printf("Invalid vertex.\n");
            return 1;
        }
    }

    for (int i = 0; i < e - 1; i++)
    {
        for (int j = i + 1; j < e; j++)
        {
            if (edges[i].w > edges[j].w)
            {
                Edge t = edges[i];
                edges[i] = edges[j];
                edges[j] = t;
            }
        }
    }

    int parent[n];

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    printf("\nEdges in MST:\n");

    int count = 0;
    int total = 0;

    for (int i = 0; i < e && count < n - 1; i++)
    {
        int x = find(parent, edges[i].u);
        int y = find(parent, edges[i].v);

        if (x != y)
        {
            printf("%d - %d (%d)\n",
                   edges[i].u,
                   edges[i].v,
                   edges[i].w);

            unionSet(parent, x, y);
            count++;
            total += edges[i].w;
        }
    }

    if (count != n - 1)
    {
        printf("MST does not exist. Graph is disconnected.\n");
    }
    else
    {
        printf("Total cost of MST = %d\n", total);
    }

    return 0;
}
