#include <iostream>
#include <chrono>
#include <stdlib.h>     /* srand, rand */
#include <thread>
#include <vector>
#include "PriorityQ.h"


using namespace std;



int main() {
    /*
     vector<thread> vec(2); //cantidad de threads que quieras usar
    vec[0] = thread(Agregar,ref(s), 5) ;//si el parametro 2 es una referencia
    vec[0].join;
   // thread th1 (&arbol::sumar, this, ref(pos->nodes[i]), ref(sumas[i]));
   // thread th1 (s,5);
   // th1.join();

   // s(5);
    s.insert(8);*/
    /*
    s.thr(5);
    cout << s.top() << endl;
    s.print();*/

    /*
    s.insert(5);
    s.insert(1);
    s.insert(18);
    s.insert(6);
    s.insert(3);
      */
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
    

    // s.print();


  // s.pop();
   //s.print();
}