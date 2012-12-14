#include <utility>  // swap()
#include "GraphEdge.h"

GraphEdge GraphEdge::SwapFromTo()
{
  GraphEdge e(*this);
  std::swap(e.m_from, e.m_to);
  return e;
}

