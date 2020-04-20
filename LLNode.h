#include<iostream>
using namespace std;

template<class T>
class LLNode
{
public:
    T info;
    LLNode<T>* next;

public:
    LLNode(){
        next = NULL;
    }

    LLNode(T el){
        info = el;
        next = NULL;
    }
    LLNode(T el, LLNode<T>* n){
        info = el;
        next = n;
    }

    ~LLNode(){}

    T print() {return info;}

    bool isEqual(T el){
        return info == el;
    }

};
