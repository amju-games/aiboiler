#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED

#include <vector>
#include <deque>
#include "Graph.h"

class Dfs
{
public:
  Dfs(Graph* g);
  bool SearchWithTrail(int from, int to, Trail* trail);
  bool SearchNoTrail(int from, int to);

private:
  Graph* m_graph;
};

#endif
