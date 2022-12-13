#include <iostream>
#include <chrono>
#include <stdlib.h>     /* srand, rand */
#include <thread>
#include <vector>
#include "PriorityQ.h"


using namespace std;



int main() {
    
    srand(time(NULL));
    PQueue s;
        chrono::time_point<std::chrono::system_clock> start, end;
      int n[5]={100,1000,10000,100000,1000000};//el ultimo 16 sec aprox
      //PQueue<skiplist> s;
      start = std::chrono::system_clock::now();
      for(int i=0;i<5;i++){
        start = std::chrono::system_clock::now();
        s.thr(n[i]);

      end = std::chrono::system_clock::now();


      cout <<n[i]<<" Datos -> Execution Time: "  << chrono::duration_cast<chrono::microseconds>(end-start).count() << "\tmicrosec\n";
        }
    

   
}
