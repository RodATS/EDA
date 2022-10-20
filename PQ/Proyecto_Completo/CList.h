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
        head = tail = 0;
        nelem = 0;
    }
    ~CList()
    {
        //...
    }


//--------------------------------------------------------
    void push_back(T x, int p)
    {
        CNode<T>* n = new CNode<T>(x,p);
        if (!nelem)
            head =  n;
        else
        {
          //mayor a menor
          if(max==0){
            if(head->prioridad > p){
              n->next=head;
              head=n;
            }
            else{
              CNode<T>* st;
              st=head;
              while(st->next != NULL && st->next->prioridad < p){
                st=st->next;
              }
              n->next=st->next;
              st->next=n;
            }
          }
            //menor a mayor
          else{
            if(head->prioridad < p){
              n->next=head;
              head=n;
            }
            else{
              CNode<T>* st;
              st=head;
              while(st->next != NULL && st->next->prioridad > p){
                st=st->next;
              }
              n->next=st->next;
              st->next=n;
            }
          }
        }
        nelem ++;
    }
    
    void pop_back()
    {
        
        CNode<T>* n =head;
        CNode<T>* aux= head;
        n=n->next;
        delete aux;
        head = n;
        nelem --;
        return;
      
    }

    T top_front(){
      return head->value;
    }

    void turn_on_max(bool n){
      max=n;
    }
   
    T& operator[](int i)
    {
        CNode<T>* n = head;
        for (int k = 0; k != i; k++)
            n = n->next;
        return n->value;
    }
    
    
    void Print2()
    {
        std::cout<<"\n";
        for (int i = 0; i < nelem; i++)
            std::cout<<(*this)[i]<<" ";
      cout<<endl;
    }
    
private:
    CNode<T>* head, *tail;
    int nelem;
    bool max=0;
};




#endif