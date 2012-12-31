#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED

#include "Graph.h"

class Dfs
{
public:
  Dfs(Graph* g);
  bool SearchWithTrail(int from, int to, Trail* trail);
  bool SearchNoTrail(int from, int to);

  // Use stack of ints, not edges
  bool SearchNoTrailNodesNotEdges(int from, int to, Trail* trail); // simplest, start with this one?
  bool SearchWithTrailNodesNotEdges(int from, int to, Trail* trail);

private:
  Graph* m_graph;
};

#endif
