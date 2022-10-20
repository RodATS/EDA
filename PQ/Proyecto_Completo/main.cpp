#include <iostream>
#include "Nodo.h"
#include "CList.h"
#include "PriorityQ.h"
using namespace std;


int main(){
  int n=4;
  bool mx=false;//mayor=true, menor=false
   PQueue<int, CList<int>> q(mx);
  //elemento- prioridad
  
  q.insert(4,1);
  q.insert(9,4);
  q.insert(7,5);
  q.insert(10,3);

  q.print();

  q.insert(11,2);
  n++;

  for(int i=0;i<n;i++){
    cout<<q.top()<<"\t";
    q.pop();
  }
  cout<<endl;
  //q.print();
  
  PQueue<string, CList<string>> Lq(mx);
  Lq.insert("a",3);
  Lq.insert("b",2);
  Lq.insert("a",1);
  Lq.insert("c",8);
  Lq.insert("f",5);
  Lq.insert("j",4);
  Lq.insert("h",5);
  Lq.insert("n",6);

  for(int i=0;i<8;i++){
    cout<<Lq.top()<<"\t";
    Lq.pop();
  }
  cout<<endl;
  
  
  
  return 0;
}