// Ryan Carlson, ID# 918062981

#include "Shape.h"
using namespace std;


Rectangle::~Rectangle(void){}
bool Rectangle::overlaps(const Shape& s) const{
  return s.overlaps(*this);
}
bool Rectangle::overlaps(const Circle& r) const{
  return r.overlaps(*this);
}
bool Rectangle::overlaps(const Rectangle& r) const{
  if((position.x + width)<=r.position.x || position.x>=(r.position.x + r.width)){
    return false;
  }
  if((position.y + height)<=r.position.y || position.y>=(r.position.y + r.height)){
    return false;
  }
  return true;
}

bool Rectangle::fits_in(const Rectangle& r) const{
  if(position.x < r.position.x || (position.x + width) > (r.position.x + r.width)){
    return false;
  }
  if(position.y < r.position.y || (position.y + height) > (r.position.y + r.height)){
    return false;
  }
  return true;
}

void Rectangle::draw(void) const{
  cout << "<rect x=\"" << position.x << "\" y=\"" <<
   position.y << "\" width=\"" << width <<
    "\" height=\"" << height << "\"/>" << endl;
}


Circle::~Circle(void){}

bool Circle::overlaps(const Shape& s) const{
  return s.overlaps(*this);
}
bool Circle::overlaps(const Circle& r) const{
  if(((center.x-r.center.x)*(center.x-r.center.x) +
   (center.y-r.center.y)*(center.y-r.center.y)) < (radius + r.radius)){
     return true;
   }
   return false;
}

bool Circle::overlaps(const Rectangle& r) const{
  int closestX, closestY;
  closestX = min(max(center.x,r.position.x),r.position.x + r.width);
  closestY = min(max(center.y,r.position.y),r.position.y + r.height);
  int distSquared = ((center.x-closestX)*(center.x-closestX) +
   (center.y-closestY)*(center.y-closestY));
   if(distSquared<(radius*radius)){
     return true;
   }
   return false;
}


bool Circle::fits_in(const Rectangle& r) const{
  if((center.x+radius)>(r.position.x + r.width) || (center.x-radius) < (r.position.x)){
    return false;
  }
  if((center.y+radius)>(r.position.y + r.height) || (center.y-radius) < (r.position.y)){
    return false;
  }
  return true;
}



void Circle::draw(void) const{
  cout << "<circle cx=\"" << center.x << "\" cy=\"" <<
   center.y << "\" r=\"" << radius << "\"/>" << endl;
}
