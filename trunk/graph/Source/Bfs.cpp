#include <iostream>
#include <set>
#include <queue>
#include "Bfs.h"

Bfs::Bfs(Graph* g) : m_graph(g) 
{
}

bool Bfs::SimpleBfs(int start, int end)
{
  // Need to remember which nodes we have already visited
  std::set<int> visited;
  std::queue<int> toVisit;
  toVisit.push(start);
  while (!toVisit.empty())
  {
    int node = toVisit.front();
    toVisit.pop();
    visited.insert(node);
    if (node == end)
    {
      std::cout << "Found path!\n";
      return true;
    }
    else
    {
      const EdgeList& edgelist = m_graph->GetEdgeList(node);
      for (EdgeList::const_iterator it = edgelist.begin(); it != edgelist.end(); ++it)
      {
        const GraphEdge& childEdge = *it;
        int to = childEdge.GetTo();
        if (visited.count(to) == 0)
        {
          toVisit.push(to);
          // ...we mark node as visited right away here
          visited.insert(to);
        }
      }
    }
  }
  std::cout << "No path!\n";
  return false;
}

bool Bfs::SearchNoTrail(int from, int to)
{
  // Need to remember which nodes we have already visited
  std::set<int> visited;

  // Breadth first uses a queue to hold nodes we will visit
  std::queue<GraphEdge> nodesToVisit;

  float cost = 0; // dummy value
  // Put dummy edge in queue to start search. TODO better way, e.g. do/while ?
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

    breadcrumbs[e.GetTo()] = e.GetFrom(); // map version
    //breadcrumbs.push_back(e); // vector version
    // In addition to here....
    visited.insert(e.GetTo());

    if (e.GetTo() == to)
    {
      // We have found the finish!
      std::cout << "Successfully got to the finish!\n";
      MakeTrail(from, to, breadcrumbs, trail);
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
