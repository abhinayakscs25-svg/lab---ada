#include <stdio.h>

int main()
{
    int n, cost[10][10], dist[10], visited[10];
    int i, j, u, v, min, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    printf("Enter source vertex: ");
    scanf("%d",&src);

    for(i=0;i<n;i++)
    {
        dist[i]=cost[src][i];
        visited[i]=0;
    }

    visited[src]=1;
    dist[src]=0;

    for(i=1;i<n-1;i++)
    {
        min=999;

        for(j=0;j<n;j++)
        {
            if(!visited[j] && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }

        visited[u]=1;

        for(v=0;v<n;v++)
        {
            if(!visited[v] && dist[u]+cost[u][v]<dist[v])
                dist[v]=dist[u]+cost[u][v];
        }
    }

    printf("Shortest distances:\n");

    for(i=0;i<n;i++)
        printf("%d -> %d = %d\n",src,i,dist[i]);

    return 0;
}
