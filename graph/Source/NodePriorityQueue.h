#ifndef NODE_PRIORITY_QUEUE_H_INCLUDED
#define NODE_PRIORITY_QUEUE_H_INCLUDED

#include <vector>
#include <map>

// Was vector, but map gives us possibility of sparse array of costs
typedef std::map<int, float> Costs;

class NodePriorityQueue
{
public:
  NodePriorityQueue(Costs* costs) : m_costs(costs) {}

  int Top() const;
  void Pop();
  void Push(int);
  bool IsEmpty() const;
  void ReSort();

private:
  Costs* m_costs;

  typedef std::vector<int> Nodes; 
  Nodes m_nodes;
};

#endif
