#include <iostream>
#include <set>
#include <queue>
#include "Bfs.h"

Bfs::Bfs(Graph* g) : m_graph(g) 
{
}

bool Bfs::SearchNoTrail(int from, int to)
{
  // Need to remember which nodes we have already visited
  std::set<int> visited;

  // Breadth first uses a queue to hold nodes we will visit
  std::queue<GraphEdge> nodesToVisit;

  float cost = 0; // dummy value
  // Put dummy edge in stack to start search. TODO better way, e.g. do/while ?
  nodesToVisit.push(GraphEdge(from, from, cost));

  while (!nodesToVisit.empty()) 
  {
    GraphEdge e = nodesToVisit.front();
    nodesToVisit.pop();

    std::cout << "Trying edge from " << e.GetFrom() << " to " << e.GetTo() << "\n";

    // In addition to here....
    visited.insert(e.GetTo());

    if (e.GetTo() == to)
    {
      // We have found the finish!
      std::cout << "Successfully got to the finish!\n";
      return true;
    }
    else
    {
      // Push unvisited neighbours onto stack
      const EdgeList& edgelist = m_graph->GetEdgeList(e.GetTo());
      for (EdgeList::const_iterator it = edgelist.begin(); it != edgelist.end(); ++it)
      {
        const GraphEdge& childEdge = *it;
        if (visited.count(childEdge.GetTo()) == 0)
        {
          nodesToVisit.push(childEdge);
          // ...we mark node as visited right away here
          visited.insert(childEdge.GetTo());
        }
      }
    }
  }
  return false;
}

bool Bfs::SearchWithTrail(int from, int to, Trail* trail)
{
  // Need to remember which nodes we have already visited
  std::set<int> visited;
  typedef std::vector<GraphEdge> Breadcrumbs;
  Breadcrumbs breadcrumbs;

  // Breadth first uses a queue to hold nodes we will visit
  std::queue<GraphEdge> nodesToVisit;

  float cost = 0; // dummy value
  // Put dummy edge in stack to start search. TODO better way, e.g. do/while ?
  nodesToVisit.push(GraphEdge(from, from, cost));

  while (!nodesToVisit.empty()) 
  {
    GraphEdge e = nodesToVisit.front();
    nodesToVisit.pop();

    std::cout << "Trying edge from " << e.GetFrom() << " to " << e.GetTo() << "\n";

    breadcrumbs.push_back(e); 
    // In addition to here....
    visited.insert(e.GetTo());

    if (e.GetTo() == to)
    {
      // We have found the finish!
      std::cout << "Successfully got to the finish!\n";
      // We have found the finish! Loop back through the breadcrumbs to create the trail.
      int node = to;
      trail->push_back(node);
      for (Breadcrumbs::reverse_iterator it = breadcrumbs.rbegin(); it != breadcrumbs.rend(); ++it)
      {
        const GraphEdge& e = *it;
        if (e.GetTo() == node && e.GetTo() != e.GetFrom()) // skip dummy node
        {
          node = e.GetFrom();
          trail->push_front(node);
        }
      }
      return true;
    }
    else
    {
      // Push unvisited neighbours onto stack
      const EdgeList& edgelist = m_graph->GetEdgeList(e.GetTo());
      for (EdgeList::const_iterator it = edgelist.begin(); it != edgelist.end(); ++it)
      {
        const GraphEdge& childEdge = *it;
        if (visited.count(childEdge.GetTo()) == 0)
        {
          nodesToVisit.push(childEdge);
          // ...we mark node as visited right away here
          visited.insert(childEdge.GetTo());
        }
      }
    }
  }
  return false;
}
