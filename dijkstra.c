#include<stdio.h>
#include<stdlib.h>
void dijkstra(int n,int cost[10][10], int s,int dist[10]);

int main()
{
    int i,j,n,source,cost[10][10],dist[10];
    printf("Enter number of nodes:");
    scanf("%d",&n);
    printf("Enter cost matrix:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    printf("Enter source node:");
    scanf("%d",&source);
    dijkstra(n,cost,source,dist);
    printf("shortest path from %d is\n",source);
    for(i=1;i<=n;i++)
    {
        if(source!=i)
        {
            printf("%d->%d=%d\n",source,i,dist[i]);
        }
    }
}

void dijkstra(int n,int cost[10][10], int s,int dist[10])
{
    int i,v,c=1,min,visited[10];
    for(i=1;i<n;i++)
    {
        visited[i]=0;
        dist[i]=cost[s][i];
    }
    visited[s]=1;
    dist[s]=0;
    while(c<=n-1)
    {
        min=999;
        for(i=1;i<n;i++)
        {
            if(dist[i]<min && visited[i]==0)
            {
                min=dist[i];
                v=i;
            }
        }
        visited[v]=1;
        c++;
        for(i=1;i<n;i++)
        {
            if(dist[i]<dist[i]+cost[v][i])
                dist[i]=-dist[i]+cost[v][i];
        }
    }
}
