
// Write a C program to implement the Graph Coloring Problem using Backtracking.
#include<stdio.h>

int is_safe( int n, int graph[n][n], int vertex, int c, int color[])
{
   for(int i=0;i<n;i++)
    {
        if(graph[vertex][i]==1 &&  color[i]==c)
        {
            return 0;
        }
           
    }
    return 1;
}
int graphcoloring(int m,int n, int graph[n][n],int vertex,int color[])
{
   if (vertex==n)
   return 1;
   for(int i=1;i<=m;i++)
   {
      if (is_safe(n, graph, vertex,i,color))
      {
        color[vertex]=i;
        if (graphcoloring(m,n,graph,vertex+1,color))
        {
            return 1;
        }
        color[vertex]=0;//not colered
      }
   }
   return 0;

}

int main()
{
    int n,vertex;
   
    int m;
    printf("enter the number of color present: ");
    scanf("%d",&m);
    printf("enter the number of vertices: ");
    scanf("%d",&n);
    int graph[n][n];
    int color[n];
    printf("enter the order in which the vertices are conneced/adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
         scanf("%d", &graph[i][j]);
       }
    }
    for (int i = 0; i < n; i++)
{
    color[i] = 0;
}//initially not colored.
    if (graphcoloring(m, n, graph, 0, color))
    {
        printf("Solution exists:\n");

        for (int i = 0; i < n; i++)
        {
            printf("Vertex %d -> Color %d\n",
                   i, color[i]);
        }
    }
    else
    {
        printf("No solution exists.\n");
    }

    return 0;

}



// case 1:
// enter the number of color present: 2
// enter the number of vertices: 4
// enter the order in which the vertices are conneced/adjacency matrix:
// 0 1 0 1
// 1 0 1 0
// 0 1 0 1
// 1 0 1 0
// Solution exists:
// Vertex 0 -> Color 1
// Vertex 1 -> Color 2
// Vertex 2 -> Color 1
// Vertex 3 -> Color 2

// case 2:
// enter the number of color present: 2
// enter the number of vertices: 3
// enter the order in which the vertices are conneced/adjacency matrix:
// 0 1 1
// 1 0 1
// 1 1 0
// No solution exists.

