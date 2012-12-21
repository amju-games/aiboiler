#include <algorithm>
#include "NodePriorityQueue.h"

struct NodeOrder
{
  NodeOrder(const Costs& costs) : m_costs(costs) {}

  bool operator()(int n1, int n2) const
  {
    // We want the node with the lowest total at the root of the heap, so we
    // need the opposite of 'less-than'.
    return (m_costs[n1] > m_costs[n2]);
  }

private:
  const Costs& m_costs;
};

int NodePriorityQueue::Top() const
{
  return m_nodes.front();
}

void NodePriorityQueue::Pop()
{
  std::pop_heap(m_nodes.begin(), m_nodes.end(), NodeOrder(*m_costs));
  m_nodes.pop_back();
}

void NodePriorityQueue::Push(int n)
{
  m_nodes.push_back(n);
  std::push_heap(m_nodes.begin(), m_nodes.end(), NodeOrder(*m_costs));
}

bool NodePriorityQueue::IsEmpty() const
{
  return m_nodes.empty();
}

void NodePriorityQueue::ReSort()
{
  std::make_heap(m_nodes.begin(), m_nodes.end(), NodeOrder(*m_costs));
}


