#ifndef PRIORITYQ_H
#define PRIORITYQ_H

#include "Skip_Priority.h"

#include <iostream>
using namespace std;

template<class S>
class PQueue
{
public:
   /* PQueue(bool n){
      seq.turn_on_max(n);
    }*/

    void insert(int p)
    {   seq.insert_element(p);   }

    void pop()
    {   seq.pop_element();     }

    int top()
  {return seq.top_element();}

  void print(){
    seq.display();
  }
    
    

private:
    S seq;
};

#endif
