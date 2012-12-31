#ifndef A_STAR_H_INCLUDED
#define A_STAR_H_INCLUDED

#include "Graph.h"

class AStar
{
public:
  AStar(Graph* g);

  // Start with empty open list, better for mem usage
  bool SearchWithTrailOpenClosedLists(int from, int to, Trail* trail);

private:
  // TODO ptr to function
  float Heuristic(int from, int to);

private:
  Graph* m_graph;
};


#endif
