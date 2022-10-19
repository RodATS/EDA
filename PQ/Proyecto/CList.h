#ifndef CLIST_H
#define CLIST_H


#include <iostream>
#include "Nodo.h"
using namespace std;


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
      CNode<T>* n = head;
      for (int i = 0; i < nelem; i++){
        if(n->value<=min->value){
          min=n;
        }
        n=n->next;
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
        delete n;
        nelem --;
        min=head;
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

    T top_front(){
      return min->value;
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




#endif