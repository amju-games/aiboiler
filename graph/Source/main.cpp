#include "Graph.h"
#include "Dfs.h"
#include "Bfs.h"

int main()
{
  Graph g;
  float cost = 1.0f;
  g.AddNode(GraphNode(0));
  g.AddNode(GraphNode(1));
  g.AddNode(GraphNode(2));
  g.AddNode(GraphNode(3));
  g.AddNode(GraphNode(4));
  g.AddNode(GraphNode(5));

  g.AddEdge(GraphEdge(0, 1, cost));
  g.AddEdge(GraphEdge(0, 2, cost));
  g.AddEdge(GraphEdge(1, 2, cost));
  g.AddEdge(GraphEdge(1, 3, cost));
  g.AddEdge(GraphEdge(2, 4, cost));
  //g.AddEdge(GraphEdge(3, 4, cost));
  //g.AddEdge(GraphEdge(3, 5, cost));
  //g.AddEdge(GraphEdge(4, 5, cost));

  Trail trail;
//  Dfs dfs(&g);
//  dfs.SearchWithTrail(0, 3, &trail);

  Bfs bfs(&g);
  bfs.SearchWithTrail(0, 3, &trail);

}
