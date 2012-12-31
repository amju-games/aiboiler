#include <iostream>
#include <set>
#include <stack>
#include "Dfs.h"

Dfs::Dfs(Graph* g) : m_graph(g) 
{
}

bool Dfs::SearchNoTrail(int from, int to)
{
  // Need to remember which nodes we have already visited
  std::set<int> visited;

  // Depth first uses a stack to hold nodes we will visit
  std::stack<GraphEdge> nodesToVisit;

  float cost = 0; // dummy value
  // Put dummy edge in stack to start search. TODO better way, e.g. do/while ?
  nodesToVisit.push(GraphEdge(from, from, cost));

  while (!nodesToVisit.empty())
  {
    GraphEdge e = nodesToVisit.top();
    nodesToVisit.pop();

    std::cout << "Trying edge from " << e.GetFrom() << " to " << e.GetTo() << "\n";

    visited.insert(e.GetTo());

    if (e.GetTo() == to)
    {
      // We have found the finish! 
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
        }
      }
    }
  }
  return false;
}

bool Dfs::SearchWithTrail(int from, int to, Trail* trail)
{
  std::set<int> visited;
  Breadcrumbs breadcrumbs;

  std::stack<GraphEdge> nodesToVisit;
  float cost = 0;
  // Put dummy edge in stack
  nodesToVisit.push(GraphEdge(from, from, cost));
  while (!nodesToVisit.empty())
  {
    GraphEdge e = nodesToVisit.top();
    nodesToVisit.pop();

    std::cout << "Trying edge from " << e.GetFrom() << " to " << e.GetTo() << "\n";

    breadcrumbs[e.GetTo()] = e.GetFrom(); // map version
    // breadcrumbs.push_back(e); // vector version
    visited.insert(e.GetTo());

    if (e.GetTo() == to)
    {
      // We have found the finish! Loop back through the breadcrumbs to create the trail.
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
        }
      }
    }
  }
  return false;
}

bool Dfs::SearchWithTrailNodesNotEdges(int from, int to, Trail* trail)
{
  std::set<int> visited;
  Breadcrumbs breadcrumbs;

  std::stack<int> nodesToVisit;

  // Put dummy edge in stack
  const GraphNode& n = m_graph->GetNode(from);
  nodesToVisit.push(n.GetId());

  while (!nodesToVisit.empty())
  {
    int node = nodesToVisit.top();
    nodesToVisit.pop();

    std::cout << "\nConsidering node " << node << "...\n";

    visited.insert(node);

    if (node == to)
    {
      // We have found the finish! Loop back through the breadcrumbs to create the trail.
      MakeTrail(from, to, breadcrumbs, trail);
      return true;
    }
    else
    {
      // Push unvisited neighbours onto stack
      const EdgeList& edgelist = m_graph->GetEdgeList(node);
      for (EdgeList::const_iterator it = edgelist.begin(); it != edgelist.end(); ++it)
      {
        const GraphEdge& childEdge = *it;
        int to = childEdge.GetTo();
        if (visited.count(to) == 0)
        {
          nodesToVisit.push(to);
          breadcrumbs[to] = node; // route from 'node' to 'to'
        }
      }
    }
  }
  return false;
}

bool Dfs::SearchNoTrailNodesNotEdges(int from, int to, Trail* trail)
{
  std::set<int> visited;

  std::stack<int> nodesToVisit;

  // Put dummy edge in stack
  const GraphNode& n = m_graph->GetNode(from);
  nodesToVisit.push(n.GetId());

  while (!nodesToVisit.empty())
  {
    int node = nodesToVisit.top();
    nodesToVisit.pop();

    std::cout << "\nConsidering node " << node << "...\n";

    visited.insert(node);

    if (node == to)
    {
      return true;
    }
    else
    {
      // Push unvisited neighbours onto stack
      const EdgeList& edgelist = m_graph->GetEdgeList(node);
      for (EdgeList::const_iterator it = edgelist.begin(); it != edgelist.end(); ++it)
      {
        const GraphEdge& childEdge = *it;
        int to = childEdge.GetTo();
        if (visited.count(to) == 0)
        {
          nodesToVisit.push(to);
        }
      }
    }
  }
  return false;
}
