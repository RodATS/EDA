#include <iostream>
using namespace std;

namespace OK{
  //Funciones
  float Addition(float a, float b){
  return a+b;
  }
  
  float Subtraction(float a, float b){
    return a-b;
  }
  
  float Multiplication(float a, float b){
    return a*b;
  }
  
  float Division(float a, float b){
    return a/b;
  }


  //Estructura
  struct VectorOK{
    int *m_pVector,
    m_nCount=0,
    m_nMax=0,
    m_nDelta;
  };
  
  
  void Resize(VectorOK *pThis){
    pThis->m_nDelta=5;
    int *aux=new int[pThis->m_nMax+pThis->m_nDelta];
    for(int i=0;i<pThis->m_nCount;i++){
      aux[i]=pThis->m_pVector[i];
    }
    pThis->m_pVector=aux;
    pThis->m_nMax+=pThis->m_nDelta;
  }
  
  
  
  
  void Insertar(VectorOK *pThis, int elem){
    if(pThis->m_nCount==pThis->m_nMax){
      Resize(pThis);
      }
    pThis->m_pVector[pThis->m_nCount]=elem;
    pThis->m_nCount+=1;
  }
  
  
  void Print(VectorOK *pThis){
    for(int i=0;i<pThis->m_nCount;i++){
      cout<<pThis->m_pVector[i]<<"\t";
    }
    cout<<endl;
  }
};

int main() {
  cout<<OK::Addition(5, 10)<<endl;
  OK:: VectorOK vect;
  Insertar(&vect,5);
  Insertar(&vect,15);
  Insertar(&vect,65);
  Print(&vect);
}
