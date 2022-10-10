#include <iostream>
using namespace std;


template <class T>
class PQeque{ //array
public:

  PQeque(int size=10){
    m_size=size;
    m_v=new T[size];
  }
  ~PQeque(){
    delete m_v;
  }

//---------------------------
int divide(int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;

    pivot = m_v[start];
    left = start;
    right = end;

    // Mientras no se cruzen los índices
    while (left < right) {
        while (m_v[right] > pivot) {
            right=right-1;
        }

        while ((left < right) && (m_v[left] <= pivot)) {
            left=left+1;
        }

        //Intercambio
        if (left < right) {
            temp = m_v[left];
            m_v[left] = m_v[right];
            m_v[right] = temp;
        }
    }

    // Se da el cruce, hacemos el cambio
    temp = m_v[right];
    m_v[right] = m_v[start];
    m_v[start] = temp;

    //Nueva posición del pivot
    return right;
}


void quicksort(int start, int end)
{
    int pivot;

    if (start < end) {
        pivot = divide(start, end);

        // Ordenacion de los menores
        quicksort(start, pivot - 1);

        // Ordenacion de los mayores
        quicksort(pivot + 1, end);
    }
}

//------------
  
  void resize(){
    int *aux=new T[m_size*2];
      for(int i=0;i<m_size;i++){
        aux[i]=m_v[i];
      }
      delete m_v;
      m_v=aux;
      m_size=m_size*2;
  }
  
  
  void push(int n){
    if(ubicacion>=m_size){
      resize();
    }
    m_v[ubicacion]=n;
    quicksort(0, ubicacion);
    ubicacion++;
    
  }


  int top(){
    return m_v[0];
  }

  void pop(){
    int saco=m_v[0];
    for(int i=0;i<ubicacion;i++){
      m_v[i]=m_v[i+1];
    }
    ubicacion--;
  }
  

  void print(){
    for(int i=0;i<ubicacion;i++){
      cout<<m_v[i]<<"\t";
    }
    cout<<endl;
  }

private:
  T* m_v;
  int m_size;
  int ubicacion=0;
};

int main(){
  PQeque<int> m(5);
  m.push(5);
  m.push(14);
  m.push(1);
  m.push(8);
  m.print();
  m.push(104);
  m.push(15);
  m.push(81);
  m.push(1);
  m.print();

  cout<<m.top()<<endl;
  m.pop();
  m.print();
}
