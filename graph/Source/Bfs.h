#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED

#include <vector>
#include <deque>
#include "Graph.h"

class Bfs
{
public:
  Bfs(Graph* g);
  bool SearchWithTrail(int from, int to, Trail* trail);
  bool SearchNoTrail(int from, int to);

private:
  Graph* m_graph;
};


#endif
