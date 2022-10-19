#ifndef NODO_H
#define NODO_H


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


#endif