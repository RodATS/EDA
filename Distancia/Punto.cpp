#include <iostream>
#include <math.h>
#include <time.h> 
#include <chrono>
#include <vector>

typedef long long L;
using namespace std;


long long Distancia(long long X,long long Y, long long Z,long long x,long long y, long long z){
  return sqrt(pow(X-x,2)+pow(Y-y,2)+pow(Z-z,2));
}

int main() {
  long long x,y,z;
  int puntos=49999;//9999 49999
  auto start=chrono::system_clock::now();
  for(int i=0;i<puntos;i++)
  {
    /*x=rand()%50;
    y=rand()%50;
    z=rand()%50;*/
     Distancia(0,0,0,i,i,i);
    //Distancia(0,0,0,x,y,z);
  }

  auto end=chrono::system_clock::now();
  chrono::duration<float,milli>duration = end-start;
  cout<<duration.count()<<"\tsegundos"<<endl;
}
