#ifndef PRIORITYQ_H
#define PRIORITYQ_H

#include "CList.h"

#include <iostream>
using namespace std;

template<class T, class S>
class PQueue
{
public:
    PQueue(bool n){
      seq.turn_on_max(n);
    }

    void insert(T x, int p)
    {   seq.push_back(x,p);   }

    void pop()
    {   seq.pop_back();     }

    T top()
  {return seq.top_front();}

  void print(){
    seq.Print2();
  }
    
    

private:
    S seq;
};

#endif