#include <assert.h>
#include "Graph.h"

void Graph::AddNode(GraphNode n)
{
  // Check invariants - precondition

  if (n.GetId() < m_nextId)
  {
    // Reactivating
    m_nodes[n.GetId()] = n;
  }
  else
  {
    // Add new node, and associated edge list
    m_nodes.push_back(n);
    m_edges.push_back(EdgeList());
    m_nextId++;
  }

  // Check invariants - postcondition
}

void Graph::AddEdge(GraphEdge e)
{
  assert(e.GetFrom() < m_nextId);
  assert(e.GetTo() < m_nextId);
  // TODO Check for edge already existing. Tempted to use a set - why not ?
  
  m_edges[e.GetFrom()].push_back(e);
  m_edges[e.GetTo()].push_back(e.SwapFromTo());
}

void Graph::RemoveNode(int nodeId)
{
  assert(nodeId < m_nextId);
  // Set ID of node to -1, don't try to really erase
  m_nodes[nodeId].SetId(-1);
  m_edges[nodeId].clear();
  // Find this ID as a destination in edges for all other nodes
  // TODO
}

const GraphNode& Graph::GetNode(int nodeId) const
{
  assert(nodeId < m_nextId);
  return m_nodes[nodeId]; 
}

const GraphEdge& Graph::GetEdge(int from, int to) const
{
  assert(from < m_nextId);
  assert(to < m_nextId);
  const EdgeList& edgelist = m_edges[from];
  // Find the edge with 'to' as the destination
  EdgeList::const_iterator it = edgelist.begin();
  for (; it != edgelist.end(); ++it)
  {
    const GraphEdge& ge = *it;
    if (ge.GetTo() == to)
    {
      break;
    }
  }
  return *it;
}

const EdgeList& Graph::GetEdgeList(int nodeId) const
{
  assert(nodeId < m_nextId);
  return m_edges[nodeId];
}

bool Graph::IsEdgePresent(int from, int to) const
{
  const EdgeList& edgelist = m_edges[from];
  // Find the edge with 'to' as the destination
  EdgeList::const_iterator it = edgelist.begin();
  for (; it != edgelist.end(); ++it)
  {
    const GraphEdge& ge = *it;
    if (ge.GetTo() == to)
    {
      return true;
    }
  }
  return false;
}

int Graph::GetNumNodes() const
{
  return m_nodes.size();
}

int Graph::GetNumActiveNodes() const
{
  // Check for removed nodes
  // TODO
  return m_nodes.size(); // TEMP
}

int Graph::GetNumEdges() const
{
  int num = 0;
  int size = m_edges.size();
  for (int i = 0; i < size; i++)
  {
    num += m_edges[i].size();
  }
  return num;
}

