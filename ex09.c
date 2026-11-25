
#include <stdio.h>

#define INF 999
#define SIZE 20

int main()
{
    int n;
    int adj[SIZE][SIZE];
    int dist[SIZE];
    int visited[SIZE] = {0};
    int start;
    int u, min;

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

    printf("Enter start vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid start vertex.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
    }

    dist[start] = 0;

    for (int count = 0; count < n; count++)
    {
        min = INF;
        u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
        {
            break;
        }

        visited[u] = 1;

        for (int i = 0; i < n; i++)
        {
            if (adj[u][i] > 0 && !visited[i] &&
                dist[u] + adj[u][i] < dist[i])
            {
                dist[i] = dist[u] + adj[u][i];
            }
        }
    }

    printf("\nShortest distances from %d:\n", start);

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
        {
            printf("%d -> %d : INF\n", start, i);
        }
        else
        {
            printf("%d -> %d : %d\n", start, i, dist[i]);
        }
    }

    return 0;
}
