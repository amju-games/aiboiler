#include "Graph.h"

void MakeGraph(Graph* graph)
{
  int nodeId = 0;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      GraphNode gn(nodeId);
      nodeId++;

      gn.SetPos(Vec2f(i, j));

      graph->AddNode(gn);

      if (i > 0)
      {
        graph->AddEdge(GraphEdge(nodeId - 1, nodeId));
      }

      if (j > 0)
      {
        graph->AddEdge(GraphEdge(nodeId - 4, nodeId));
      }
    }
  }
}