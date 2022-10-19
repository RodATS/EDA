#include <iostream>
#include "Nodo.h"
#include "CList.h"
#include "PriorityQ.h"
using namespace std;




int main(){
  bool mx=false;//mayor=true, menor=false
  PQueue<int, CList<int>> q(mx);
  q.insert(4);
  q.insert(6);
  q.insert(2);
  q.insert(3);
  q.insert(1);
  q.insert(1);
  q.insert(8);
  q.insert(10);

  for(int i=0;i<8;i++){
    cout<<q.top()<<"\t";
    q.pop();
  }
  cout<<endl;
  
  PQueue<string, CList<string>> Lq(mx);
  Lq.insert("a");
  Lq.insert("b");
  Lq.insert("a");
  Lq.insert("c");
  Lq.insert("f");
  Lq.insert("j");
  Lq.insert("h");
  Lq.insert("n");

  for(int i=0;i<8;i++){
    cout<<Lq.top()<<"\t";
    Lq.pop();
  }
  cout<<endl;
  
  return 0;
}
