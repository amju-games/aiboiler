#ifndef DRAW_GRAPH_OPENGL_H_INCLUDED
#define DRAW_GRAPH_OPENGL_H_INCLUDED

#include "Graph.h"

void DrawGraph(const Graph& g);
void DrawGraphNodes(const Graph& g);
void DrawGraphEdges(const Graph& g);
void DrawEdgeList(const EdgeList& e, const Graph& g);
void DrawTrail(const Trail& tr, const Graph& g);

#endif
