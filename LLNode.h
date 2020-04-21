#include<iostream>
using namespace std;

template<class string>
class LLNode
{
public:
    string info;
    LLNode<string>* next;

public:
    LLNode(){
        next = NULL;
    }

    LLNode(string el){
        info = el;
        next = NULL;
    }
    LLNode(string el, LLNode<string>* n){
        info = el;
        next = n;
    }

    ~LLNode(){}

    string print() {return info;}

    bool isEqual(string el){
        return info == el;
    }

};
