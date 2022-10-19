#include <iostream>
#include "Nodo.h"
#include "CList.h"
#include "PriorityQ.h"
using namespace std;




int main(){
  PQueue<int, CList<int>> q;
  q.insert(4);
  q.insert(6);
  q.insert(2);
  q.insert(3);
  q.insert(1);
  q.insert(1);
  q.insert(8);
  cout<<q.top()<<endl;
  q.pop();
  cout<<q.top()<<endl;
  q.pop();
  cout<<q.top()<<endl;
  q.pop();
  
  /*
  PQueue<string, CList<string>> q;
  q.insert("a");
  q.insert("b");
  q.insert("a");
  q.insert("c");
  q.insert("f");
  q.insert("j");
  q.insert("h");
  cout<<q.top()<<endl;
  q.pop();
  cout<<q.top()<<endl;
  q.pop();
  cout<<q.top()<<endl;
  q.pop();
  */
  return 0;
}
