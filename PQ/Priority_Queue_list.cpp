#include <iostream>
using namespace std;

template<class T>
struct CNode
{
    CNode(T x)
    {
        value = x;
        next = prev = 0;
    }
    T value;
    CNode<T> *next, *prev;
};

template<class T>
class CList
{
public:
    CList()
    {
        head = tail =min = 0;
        nelem = 0;
    }
    ~CList()
    {
        //...
    }

    void look_min(){
      for (CNode<T>* n = head; n != 0; n = n->next )
        if(n->value<=min->value){
          min=n;
        }
    }   
    void push_back(T x)
    {
        CNode<T>* n = new CNode<T>(x);
        if (!nelem)
            head = tail = min = n;
        else
        {
          if(min->value > n->value){
            min=n;
          }
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
        nelem ++;
    }
    
    void pop_back()
    {
        
      if(min==tail){
        CNode<T>* n= tail;
        tail=n->prev;
        nelem --;
        min=head;
        delete n;
        look_min();
        return;
      }
      if(min==head){
        CNode<T>* n =head;
        CNode<T>* aux= head;
        n=n->next;
        delete aux;
        head = n;
        min=head;
        nelem --;
        look_min();
        return;
      }
      
        CNode<T>* ant= min->prev;
        CNode<T>* des= min->next;
        CNode<T>* aux= min;
        ant->next=aux->next;
        des->prev=aux->prev;
        nelem --;
        min=head;
        delete aux;
        
        look_min();
    }

    void top_front(){
      cout<<min->value<<endl;;
    }
    /*
    void push_front(T x)
    {
        CNode<T>* n = new CNode<T>(x);
        if (!nelem)
            head = tail = n;
        else
        {
            n->next = head;
            head->prev = n;
            head = n;
        }
        nelem ++;
    }
    

    void pop_front()
    {
        CNode<T>* n =head;
        CNode<T>* aux= head;
        n=n->next;
        delete aux;
        head = n;
        nelem --;
    }
void print()
    {
        std::cout<<"\n";
        for (CNode<T>* n = head; n != 0; n = n->next )
            std::cout<<n->value<<" ";
        cout<<endl;
    }
*/
    
    T& operator[](int i)
    {
        CNode<T>* n = head;
        for (int k = 0; k != i; k++)
            n = n->next;
        return n->value;
    }
    
    
    void print2()
    {
        std::cout<<"\n";
        for (int i = 0; i < nelem; i++)
            std::cout<<(*this)[i]<<" ";
      cout<<endl;
    }
    
private:
    CNode<T>* head, *tail, *min;
    int nelem;
};

template<class T, class S>
class CQueue
{
public:
    void insert(T x)
    {   seq.push_back(x);   }
    void pop()
    {   seq.pop_back();     }
    void top()
  {seq.top_front();}
    
    void print()
    {seq.print2();}
    

private:
    S seq;
};

int main(){
  CQueue<int, CList<int>> q;
    q.insert(1);
    q.insert(6);
    q.insert(2);
    q.insert(3);
    q.print();
    q.top();
    q.pop();
    q.print();
  
    q.top();
  q.pop();
    q.print();
  q.top();
   q.pop();
    q.print();
  
  
  return 0;
}
