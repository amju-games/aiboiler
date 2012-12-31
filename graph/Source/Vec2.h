#ifndef VEC2_H_INCLUDED
#define VEC2_H_INCLUDED

struct Vec2f
{
  float x, y;

  Vec2f() : x(0), y(0) {}
  Vec2f(float fx, float fy) : x(fx), y(fy) {}

  float SqLen() { return x * x + y * y; }
  Vec2f operator-(const Vec2f& v) const { return Vec2f(x - v.x, y - v.y); }
};

#endif
