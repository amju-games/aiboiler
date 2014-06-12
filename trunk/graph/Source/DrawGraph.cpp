#include "Graph.h"

void Draw(Graph* graph)
{
  int n = graph->GetNumNodes();
  for (int i = 0; i < n; i++)
  {
    const GraphNode& gn = graph->GetNode(i);

    glPushMatrix();
      Vec2f pos = gn.GetPos();
      glTranslatef(pos.x, pos.y, 0);
      glutSolidCube(0.2);
    glPopMatrix();

    // Get edge list for current node (gn)
    const EdgeList& edgelist = graph->GetEdgeList(i);

    // Loop over the edges in the edge list
    for (EdgeList::const_iterator it = edgelist.begin();
         it != edgelist.end();
         ++it)
    {
      // For each edge, get the destination node
      const GraphEdge* edge = it;
      int destId =  edge.GetDest();
      const GraphNode& dest = graph->GetNode(destId);

      // Draw a line seg from gn pos to dest pos
      Vec2f destPos = dest.GetPos();

      glBegin(GL_LINES);
        glVertex3f(pos.x, pos.y, 0);
        glVertex3f(destPos.x, destPos.y, 0);
      glEnd();
    }
  }
}
