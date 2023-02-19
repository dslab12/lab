#include <stdio.h>
#include <stdlib.h>
int n;
struct node
{
    int data;
    struct node *addr;
} *newNode, *last, *curr;
void readGraph(struct node *adj[])
{
    int k, data;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the number of Adjacent Nodes of %d : ", i);
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            printf("\nEnter the value of Neighbour : ");
            scanf("%d", &data);
            newNode = (struct node *)malloc(sizeof(struct node *));
            newNode->data = data;
            newNode->addr = NULL;
            if (adj[i] == NULL)
            {
                adj[i] = newNode;
            }
            else
            {
                last->addr = newNode;
            }
            last = newNode;
        }
    }
}

void printGraph(struct node *adj[])
{
    for (int i = 0; i < n; i++)
    {
        curr = adj[i];
        printf("\nNeighbours of %d are : ", i);
        while (curr != NULL)
        {
            printf("\n%d", curr->data);
            curr = curr->addr;
        }
    }
}

void bfs(struct node *adj[], int start, int visited[])
{
    int queue[n], rear = 0, front = 0;
    queue[rear++] = start;
    visited[start] = 1;
    while (front != rear)
    {
        int current = queue[front++];
        printf("\n%d", current);
        curr = adj[current];
        while (curr != NULL)
        {
            if (visited[curr->data] != 1)
            {
                queue[rear++] = curr->data;
                visited[curr->data] = 1;
            }
            curr = curr->addr;
        }
    }
}

void DFS(struct node *adj[], int start, int visited[])
{
    printf("\n%d", start);
    visited[start] = 1;
    curr = adj[start];
    while (curr != NULL)
    {
        if (visited[curr->data] != 1)
        {
            DFS(adj, curr->data, visited);
        }
    }
}
int main()
{
    printf("\nEnter the number of Vertices : ");
    scanf("%d", &n);
    struct node *adj[n];
    int visited[n];
    int ch, start;

    for (int i = 0; i < n; i++)
    {
        adj[i] = NULL;
    }
    readGraph(adj);
    do
    {
        printf("\n1-BFS\n2-DFS\n3-Print Adjacency List\n4-Exit");
        printf("\nEnter Your Choice : ");
        scanf("\n%d", &ch);
        switch (ch)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                visited[i] = 0;
            }
            printf("Enter the starting vertex : ");
            scanf("\n%d", &start);
            bfs(adj, start, visited);
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                visited[i] = 0;
            }
            printf("Enter the starting vertex : ");
            scanf("\n%d", &start);
            bfs(adj, start, visited);
            break;
        case 3:
            printGraph(adj);
        default:
            break;
        }
    } while (ch != 4);

    printGraph(adj);
}