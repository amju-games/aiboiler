#ifndef GRAPH_EDGE_H_INCLUDED
#define GRAPH_EDGE_H_INCLUDED

class GraphEdge
{
public:
  GraphEdge() : m_from(-1), m_to(-1), m_cost(0) {}
  GraphEdge(int from, int to, float cost) : m_from(from), m_to(to), m_cost(cost) {}

  int GetFrom() const { return m_from; }
  int GetTo() const { return m_to; }
  float GetCost() const { return m_cost; }

  GraphEdge SwapFromTo();

private:
  int m_from;
  int m_to;
  float m_cost;
};

#endif
