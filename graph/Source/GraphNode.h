#ifndef GRAPH_NODE_H_INCLUDED
#define GRAPH_NODE_H_INCLUDED

#include "Vec2.h"

class GraphNode
{
public:
  GraphNode() : m_id(-1), m_data(0) {}
  GraphNode(int id, void* data = 0) : m_id(id), m_data(data) {}

  void SetId(int id) { m_id = id; }
  int GetId() const { return m_id; }

  void SetPos(const Vec2f pos) { m_pos = pos; }
  const Vec2f& GetPos() const { return m_pos; }

  void* GetData() { return m_data; }
  void SetData(void* data) { m_data = data; }

private:
  Vec2f m_pos;
  int m_id;
  void* m_data;
};

#endif
