#ifndef PRIORITYQ_H
#define PRIORITYQ_H

#include "Skip_Priority.h"

#include <iostream>
#include <vector>
#include <thread>
using namespace std;

//template<class S>
class PQueue
{
public:
   /* PQueue(bool n){
      seq.turn_on_max(n);
    }*/
    void operator()(int num){
      seq.insert_element(num);
    }
    
    void insert(int p)
    { seq.insert_element(p);   
      }

    void thr(int num) {
        vector<thread> threads(2);
        for (int i = 0; i < 2; i++) {
            threads[i]=thread(&PQueue::insert, this, num);
        }
        for (int i = 0; i < 2; i++) {
            threads[i].join();
        }
    }


    void pop()
    {   seq.pop_element();     }

    int top()
  {return seq.top_element();}

  void print(){
    seq.display();

    
  }
    
    

private:
    skiplist seq;
};

#endif