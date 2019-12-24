#include <stdio.h>
#include <stdlib.h>
 
typedef int Vertex;
#define x 10000 
#define size 6
 
int Graph[size][size] =
 
 
{
 x, 1, 12, x, x, x,
 x, x, 9, 3, x, x, 
 x, x, x, x, 5, x, 
 x, x, 4, x, 13, 15, 
 x, x, x, x, x, 4, 
 x, x, x, x, x, x, 
};
int Graph_Dist[size] = { x,x,x,x,x,x };
int Graph_Path[size] = { -1,-1,-1,-1,-1,-1 };
int Graph_Order[size] = { 0 };
 
void
Dijkstra(Vertex V0)
{
 Vertex V, W;
 int Order;
 Graph_Path[V0 - 1] = 0;
 Graph_Dist[V0 - 1] = 0;
 Graph_Order[V0 - 1] = 1;
 for (Order = 1; Order <= size; Order++)
 {
  for (V = 0; V < size; V++)
  {
   if (Graph_Order[V] == Order)
   {
    for (W = 0; W<size; W++)
    {
     if (Graph[V][W]!=x&&Graph_Dist[W] > Graph_Dist[V] + Graph[V][W])
      
     {
      Graph_Dist[W] = Graph_Dist[V] + Graph[V][W];
      Graph_Path[W] = V+1;
      Graph_Order[W] = Order + 1;
     }
    }
   }
 
  }
 }
}
 
void printarray(int a[]){
    int i =0;
 for (i = 1; i < size; i++)
  printf("%d ", a[i]);
}
 
void main()
{
 Dijkstra(1);
