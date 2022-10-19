#include <iostream>
#include "Nodo.h"
#include "CList.h"
#include "PriorityQ.h"
using namespace std;




int main(){

  bool mx=false;//mayor=true, menor=false
   PQueue<int, CList<int>> q(mx);
  q.insert(4,8);
  q.insert(6,2);
  q.insert(2,3);
  q.insert(3,4);
  q.insert(1,5);
  q.insert(1,6);
  q.insert(8,7);
  q.insert(10,1);

  q.print();
  
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