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

  // Use queue of node IDs, not edges - simpler
  bool SimpleBfs(int from, int to);
  bool SimpleBfsWithTrail(int start, int end, Trail* trail);

private:
  Graph* m_graph;
};


#endif
