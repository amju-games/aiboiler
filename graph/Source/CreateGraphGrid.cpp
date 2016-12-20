#include <math.h>
#include <stdlib.h> // rand()
#include "CreateGraphGrid.h"
#include "Graph.h"

static const int GRID_SIZE = 10;
static const float COST = 1.0f;
static const float DIAG_COST = COST * (float)sqrt(2.0);

void CreateGraphGrid(Graph* g)
{
  int id = 0;

  for (int i = 0; i < GRID_SIZE; i++)
  {
    for (int j = 0; j < GRID_SIZE; j++)
    {
      Vec2f pos((float)j * 10.0f, (float)i * 10.0f);
      GraphNode node(id, pos, 0);
      g->AddNode(node);

      if (rand() % 2 == 0)
      {
        // Don't connect
        id++;
        continue;
      }

      if (j > 0) 
      {
        GraphEdge edge(id - 1, id, COST);
        g->AddEdge(edge);
      }

      if (i > 0)
      {
        GraphEdge edge(id - GRID_SIZE, id, COST);
        g->AddEdge(edge);
      }
      
      if (i > 0 && j > 0)
      {
        GraphEdge edge(id - GRID_SIZE - 1, id, DIAG_COST);
        g->AddEdge(edge);
      }
      
      id++;
    }
  }

}

