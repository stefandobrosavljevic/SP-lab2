#include"LLNode.h"
#include<exception>
#include<iostream>
using namespace std;

template<class T>
class LList
{
public:
    LLNode<T>* head;
   
    LList() {head = NULL;}

    ~LList(){
        while(!prazna())
            T pom = brisiSaPocetka();
    }

    bool prazna() {return head == NULL;} 

    void dodajNaPocetak(T el);

    void dodajNaKraj(T el){
        LLNode<T>* pom = head;
        if(!prazna())
        {
            while(pom->next != NULL)
            {
                pom = pom->next;
            }
            LLNode<T>* temp = new LLNode<T>(el);
            pom->next = temp;
        }
    }

    T brisiSaPocetka(){
        if(prazna())
            throw exception();
        T el = head->info;
        LLNode<T>* pom = head;
        if(head->next == NULL)
            head = NULL;
        else
            head = head->next;
        delete pom;
        return el;
    }

    T brisiSaKraja(){
        T el;
        if(prazna())
            throw exception();
        else if(head->next == NULL)
        {
            el = head->info;
            delete head;
            head = NULL;
        }
        else
        {
            LLNode<T>* pom = head;
            while(pom->next->next != NULL)
            {
                pom = pom->next;
            }
            el = pom->next->info;
            delete pom->next;
            pom->next = NULL;
        }
        return el;
    }
    
    LLNode<T>* pronadji(T el){
        if(prazna())
            throw exception();
        else if(head->info == el)
            return head;
        else
        {
            LLNode<T>* pom = head;
            while(pom->info != el && pom->next != NULL)
            {
               pom = pom->next;
            }
            if(pom->next == NULL)
            {
                cout << "Nema elementa u listi" << endl;
                throw exception();
            }
            return pom;
        }
    }

    LLNode<T>* uzmiHead() {return head;}

    LLNode<T>* uzmiSledeci(LLNode<T>* pom){
        if(pom->next == NULL)
            throw exception();
        return pom->next;
    }

    T uzmiSled(T el)
    {
        LLNode<T>* pom = pronadji(el);
        if (pom->next == NULL) {
            cout << "Element nema sledeci u listi" << endl;
            throw exception();
        }
        return pom->next->info;
    }

    T getHeadEl() { return head->info; }

    void stampaj(){
        if(!prazna())
        {
            for(LLNode<T>* pom = head; pom != NULL; pom = pom->next)
                cout << pom->print() << " ";
            cout << endl;
        }
    }

    bool uListi(T el){
        LLNode<T>* pom = head;
        while(pom->info != el && pom->next != NULL)
        {
            pom = pom->next;
        }
        if(pom->next == NULL)
            return false;
        return true;
    }

    void brisi(T el){
        LLNode<T>* pom = head;
        while(pom->next->info != el && pom->next->next != NULL)
        {
            pom = pom->next;
        }
        if(pom->next->next == NULL)
            throw exception();
        LLNode<T>* x = pom->next->next;
        delete pom->next;
        pom->next = x;
    }

};

template<class T>
void LList<T>::dodajNaPocetak(T el){
    head = new LLNode<T>(el, head);
}
