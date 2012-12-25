#include "DrawGraphOpenGL.h"
#include <gl/glut.h>

static const float NODE_SIZE = 3.0f;

void DrawGraph(const Graph& g)
{
  DrawGraphNodes(g);
  glLineWidth(2.0f);
  DrawGraphEdges(g);
}

void DrawGraphNodes(const Graph& g)
{
  int num = g.GetNumNodes();
  for (int i = 0; i < num; i++)
  {
    const GraphNode& node = g.GetNode(i);
    const Vec2f& v = node.GetPos();
    glPushMatrix();
    glTranslatef(v.x, 0, v.y);
    //glutSolidCube(NODE_SIZE);
    glutSolidSphere(NODE_SIZE, 8, 8);
    glPopMatrix();
  }

}

void DrawGraphEdges(const Graph& g)
{
  int num = g.GetNumNodes();
  for (int i = 0; i < num; i++)
  {
    const EdgeList& e = g.GetEdgeList(i);
    DrawEdgeList(e, g);
  }
}

void DrawEdge(const GraphEdge& edge, const Graph& g)
{
  glDisable(GL_LIGHTING);
  glBegin(GL_LINES);
  const GraphNode& from = g.GetNode(edge.GetFrom());
  const GraphNode& to = g.GetNode(edge.GetTo());
  const Vec2f& u = from.GetPos();
  const Vec2f& v = to.GetPos();
  glVertex3f(u.x, 0, u.y);
  glVertex3f(v.x, 0, v.y);
  glEnd();
  glEnable(GL_LIGHTING);
}

void DrawEdgeList(const EdgeList& e, const Graph& g)
{
  for (EdgeList::const_iterator it = e.begin(); it != e.end(); it++)
  {
    const GraphEdge& edge = *it;
    DrawEdge(edge, g);
  }
}

void DrawTrail(const Trail& tr, const Graph& g)
{
  if (tr.empty())
  {
    return;
  }

  int prev = tr[0];

  for (unsigned int i = 1; i < tr.size(); i++)
  {
    const GraphEdge& edge = g.GetEdge(tr[i], prev);
    prev = tr[i];
    DrawEdge(edge, g);
  }
}
