#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

#include "Graph.h"

class Dijkstra
{
public:
  Dijkstra(Graph* g);
  bool SearchWithTrail(int from, int to, Trail* trail);
  bool SearchNoTrail(int from, int to);

  // Start with empty open list, better for mem usage
  bool SearchWithTrailOpenClosedLists(int from, int to, Trail* trail);

private:
  Graph* m_graph;
};

void TestDijkstra();

#endif
