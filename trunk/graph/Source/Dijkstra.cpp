#include <set>
#include <assert.h>
#include <iostream>
#include "Dijkstra.h"
#include "NodePriorityQueue.h"

void TestDijkstra()
{
  Graph g;
  g.AddNode(GraphNode(0, Vec2f(1, 1)));
  g.AddNode(GraphNode(1, Vec2f(2, 2)));
  g.AddNode(GraphNode(2, Vec2f(1, 1)));
  g.AddNode(GraphNode(3, Vec2f(1, 1)));
  g.AddNode(GraphNode(4, Vec2f(1, 1)));
  g.AddNode(GraphNode(5, Vec2f(1, 1)));

  g.AddEdge(GraphEdge(0, 1, 1.0f));
  g.AddEdge(GraphEdge(0, 2, 2.0f));
  g.AddEdge(GraphEdge(1, 2, 3.0f));
  g.AddEdge(GraphEdge(1, 3, 4.0f));
  g.AddEdge(GraphEdge(2, 4, 5.0f));
  g.AddEdge(GraphEdge(3, 4, 6.0f));
  g.AddEdge(GraphEdge(3, 5, 7.0f));
  g.AddEdge(GraphEdge(4, 5, 8.0f));

  Dijkstra di(&g);
  di.SearchNoTrail(0, 5);
}

Dijkstra::Dijkstra(Graph* g) : m_graph(g) 
{
}

// Not using open/closed list - the priority queue is the open list and has ALL nodes added to it initially
// http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
bool Dijkstra::SearchNoTrail(int from, int to)
{
  Costs costs;

  // Initialise total costs vector
  NodePriorityQueue queue(&costs);
  for (int i = 0; i < m_graph->GetNumNodes(); i++)
  {
    const GraphNode& n = m_graph->GetNode(i);
    costs.push_back(9999); // ? or infinity ?
    queue.Push(n.GetId());
  }
  costs[from] = 0;
  queue.ReSort();

  int numNodesConsidered = 0;
  while (!queue.IsEmpty())
  {
    int node = queue.Top();
    queue.Pop();
    numNodesConsidered++;
    std::cout << "\nConsidering node " << node << "...\n";

    if (node == to)
    {
      // TODO Path
      std::cout << "We have found path to the finish node! Cost is " << costs[to] << "\n";
      std::cout << "Nodes considered: " << numNodesConsidered << "\n";
      return true;
    }
    else
    {
      const EdgeList& edgelist = m_graph->GetEdgeList(node);
      for (EdgeList::const_iterator it = edgelist.begin(); it != edgelist.end(); ++it)
      {
        const GraphEdge& childEdge = *it;
        int to = childEdge.GetTo();
        // Calc cost of reaching 'to' node on this edge
        std::cout << "Cost from " << node << " to " << to << " is " << childEdge.GetCost() << "\n";
        float cost = costs[node] + childEdge.GetCost();
        if (cost < costs[to])
        {
          costs[to] = cost;
          std::cout << "Best cost so far to node " << to << " is " << cost << " via " << node << "\n";
        }
        else
        {
          std::cout << "Cost to node " << to << " is " << cost << " via " << node << " - not best.\n";
        }
      }
      queue.ReSort();
    }
  }

  return false;
}
