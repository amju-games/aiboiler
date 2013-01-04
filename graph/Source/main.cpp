#include <iostream>
#include "Graph.h"
#include "Dfs.h"
#include "Bfs.h"
#include "Dijkstra.h"
#include "AStar.h"
#include "DrawGraphOpenGL.h"
#include "CreateGraphGrid.h"
#ifdef WIN32
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

Graph graph;
Trail trail;

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(50.0f, 200.0f, 200.0f, 50.0f, 0, 0, 0, 1.0, 0);

    DrawGraph(graph);
    // Superimpose path 
    glClear(GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 0, 1);
    DrawTrail(trail, graph);
    glColor3f(1, 1, 1);

    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Hello");
    glutDisplayFunc(Draw);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 1000.0); 

    CreateGraphGrid(&graph);

//    Dfs dfs(&graph);
//    dfs.SearchWithTrailNodesNotEdges(0, 55, &trail);

//    Bfs bfs(&graph);
//    bfs.SimpleBfsWithTrail(0, 57, &trail);

    Dijkstra di(&graph);
    //di.SearchWithTrailOpenClosedLists(55, 0, &trail);
    //di.SearchWithTrail(55, 0, &trail);

    AStar astar(&graph);
    astar.SearchWithTrailOpenClosedLists(55, 0, &trail);

    glutMainLoop();
}

/*
int main()
{

  float cost = 1.0f;
  g.AddNode(GraphNode(0));
  g.AddNode(GraphNode(1));
  g.AddNode(GraphNode(2));
  g.AddNode(GraphNode(3));
  g.AddNode(GraphNode(4));
  g.AddNode(GraphNode(5));

  g.AddEdge(GraphEdge(0, 1, cost));
  g.AddEdge(GraphEdge(0, 2, cost));
  g.AddEdge(GraphEdge(1, 2, cost));
  g.AddEdge(GraphEdge(1, 3, cost));
  g.AddEdge(GraphEdge(2, 4, cost));
  g.AddEdge(GraphEdge(3, 4, cost));
  g.AddEdge(GraphEdge(3, 5, cost));
  g.AddEdge(GraphEdge(4, 5, cost));

  Trail trail;
  std::cout << "Depth first\n";
  Dfs dfs(&g);
  dfs.SearchWithTrail(0, 5, &trail);
  PrintTrail(trail);

  std::cout << "Breadth first\n";
  trail.clear();
  Bfs bfs(&g);
  bfs.SimpleBfs(0, 5);
  bfs.SearchWithTrail(0, 5, &trail);
  PrintTrail(trail);

  TestDijkstra();
}
*/
