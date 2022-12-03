#include <iostream>
#include "PriorityQ.h"


using namespace std;


int main() {
  PQueue<skiplist> s;
  s.insert(5);
  s.insert(1);
  s.insert(18);
  s.insert(6);
  s.insert(3);
  s.print();

  cout<<s.top()<<endl;

  s.pop();
  s.print();
}
