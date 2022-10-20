#ifndef NODO_H
#define NODO_H


#include <iostream>
using namespace std;

template<class T>
struct CNode
{
    CNode(T x, int p)
    {
        value = x;
        prioridad=p;
        next = 0;
    }
    T value;
    int prioridad;
    CNode<T> *next;
};


#endif