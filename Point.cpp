// Ryan Carlson, ID# 918062981
#include "Point.h"
using namespace std;

Point Point::operator+(const Point& rhs) const{
  return Point(x+rhs.x,y+rhs.y);
}

Point Point::operator-(const Point& rhs) const{
  return Point(x-rhs.x,y-rhs.y);
}

ostream& operator<<(ostream& os, const Point& p){
  os << "(" << p.x << "," << p.y << ")";
  return os;
}

istream& operator>>(istream& is, Point& p){
  is >> p.x >> p.y;
}
