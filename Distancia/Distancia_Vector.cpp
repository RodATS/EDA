#include <iostream>
#include <math.h>
#include <time.h> 
#include <chrono>
#include <vector>

typedef long long L;
using namespace std;

struct Punto{
public:
  vector<L> coor;
};


void Distancia(Punto ini, Punto aux){
  L res=0;
  auto j=(aux.coor).begin();
  for(auto i=(ini.coor).begin();i<(ini.coor).end();i++,j++){
    res=res+pow((*i)+(*j),2);
  }
  res=sqrt(res);
}

void Distancia_V(vector<Punto> A){
  Punto ini=A[0];
  for(auto i=A.begin();i<A.end();i++){
    Distancia(ini,(*i));
  }
}


int main() {
 
  vector<Punto> A;
  int dimension=1000;//10000  50000
    auto start=chrono::system_clock::now();
  for(int i=0;i<100;i++)
  {
    Punto pp;
    for(int j=0;j<dimension;j++){
      (pp.coor).push_back(rand()%100);
    }
    A.push_back(pp);
  }
  Distancia_V(A);
  auto end=chrono::system_clock::now();
  chrono::duration<float,milli>duration = end-start;
  cout<<duration.count()<<"\tsegundos"<<endl;
}
