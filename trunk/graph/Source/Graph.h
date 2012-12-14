#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <deque>
#include <list>
#include <vector>
#include "GraphNode.h"
#include "GraphEdge.h"

typedef std::vector<GraphNode> Nodes;
typedef std::list<GraphEdge> EdgeList; // TODO why not set ?
typedef std::vector<EdgeList> Edges;

typedef std::deque<int> Trail;

class Graph
{
public:
  Graph() : m_nextId(0) {}

  void Clear();
  bool IsEmpty() const;

  void AddNode(GraphNode n);
  void AddEdge(GraphEdge e);
  void RemoveNode(int nodeId);

  const GraphNode& GetNode(int nodeId) const;
  const GraphEdge& GetEdge(int from, int to) const;
  const EdgeList& GetEdgeList(int nodeId) const;
  bool IsEdgePresent(int from, int to) const;

  int GetNumNodes() const;
  int GetNumActiveNodes() const;
  int GetNumEdges() const;

private:
  Nodes m_nodes;
  Edges m_edges;

  int m_nextId;
};

#endif
