#include <set>
#include <assert.h>
#include <iostream>
#include <math.h>
#include "AStar.h"
#include "NodePriorityQueue.h"

AStar::AStar(Graph* g) : m_graph(g) 
{
}

float AStar::Heuristic(int from, int to)
{
  float h = sqrt((m_graph->GetNode(to).GetPos() - m_graph->GetNode(from).GetPos()).SqLen());
  return h;
}

bool AStar::SearchWithTrailOpenClosedLists(int from, int end, Trail* trail)
{
  Breadcrumbs breadcrumbs;
  Costs g_costs; // same as Dijkstra costs
  Costs f_costs; // total of g_cost and heuristic cost (h_cost)
  std::set<int> visited; // closed list

  NodePriorityQueue queue(&f_costs);
  g_costs[from] = 0;
  f_costs[from] = Heuristic(from, end);
  queue.Push(from);


  int numNodesConsidered = 0;
  while (!queue.IsEmpty())
  {
    int node = queue.Top();
    queue.Pop();
    visited.insert(node);

    numNodesConsidered++;
    std::cout << "\nConsidering node " << node << "...\n";

    if (node == end)
    {
      // TODO Path
      std::cout << "We have found path to the finish node! Cost is " << f_costs[end] << "\n";
      std::cout << "Nodes considered: " << numNodesConsidered << "\n";

      // We have found the finish! Loop back through the breadcrumbs to create the trail.
      MakeTrail(from, end, breadcrumbs, trail);

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
        float gcost = g_costs[node] + childEdge.GetCost();

        // 'to' Not visited yet? Set cost to inifinity and add to queue
        if (visited.count(to) == 0)
        {
          g_costs[to] = gcost;
          f_costs[to] = gcost + Heuristic(to, end);
          queue.Push(to);
          // ...we mark node as visited right away here
          visited.insert(to);
          breadcrumbs[to] = node; // cheapest route from 'node' to 'to'
        }
        else if (gcost < g_costs[to])
        {
          g_costs[to] = gcost;
          f_costs[to] = gcost + Heuristic(to, end);
          std::cout << "Best cost so far to node " << to << " is " << gcost << " via " << node << "\n";
          breadcrumbs[to] = node; // cheapest route from 'node' to 'to'
        }
        else
        {
          std::cout << "Cost to node " << to << " is " << gcost << " via " << node << " - not best.\n";
        }
      }
      queue.ReSort();
    }
  }

  return false;

}

