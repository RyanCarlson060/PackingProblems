// Ryan Carlson, ID# 918062981

#include "Domain.h"
using namespace std;

Domain::Domain(void){
  sizex = 600;
  sizey = 500;
}

void Domain::addShape(const Shape* p){
  s.push_back(p);
}

void Domain::draw(void){
  cout << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>" << endl;
  cout << "<svg width=\"700\" height=\"600\"" << endl;
  cout << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
  cout << "<g transform=\"matrix(1,0,0,-1,50,550)\"" << endl;
  cout << "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">" << endl;
  cout << "<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>" << endl;

  for (int i = 0; i < s.size(); i++) {
    s[i]->draw();
  }

  cout << "</g>" << endl;
  cout << "<g transform=\"matrix(1,0,0,1,50,590)\"" << endl;
  cout <<" font-family=\"Arial\" font-size=\"32\">" << endl;
  cout << "<text x=\"0\" y=\"0\">";

  int overlaps = 0;
  int notFit = 0;

  for (int i = 0; i < s.size(); i++) {
    if(!s[i]->fits_in(Rectangle(Point(0,0),600,500))){
      notFit = 1;
    }else{
      for (int j = 0; j < s.size(); j++) {
        if(s[i] != s[j]){
          if(s[i]->overlaps(*s[j])){
            overlaps = 1;  }
        }
      }
    }
  }

  if(notFit){
    cout << "does not fit";
  }else if(overlaps){
    cout << "overlap";
  }else{
    cout << "ok";
  }

  cout << "</text>" << endl;
  cout << "</g>" << endl;
  cout << "</svg>" << endl;
}

Domain::~Domain(void){
  for (int i = 0; i < s.size(); i++) {
    delete s[i];
  }
}
