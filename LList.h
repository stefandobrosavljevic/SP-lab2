#include"LLNode.h"
#include<exception>
#include<iostream>
using namespace std;

template<class string>
class LList
{
public:
    LLNode<string>* head;
   
    LList() {head = NULL;}

    ~LList(){
        while(!prazna())
            string pom = brisiSaPocetka();
    }

    bool prazna() {return head == NULL;} 

    void dodajNaPocetak(string el){
        head = new LLNode<string>(el, head);
    }

    void dodajNaKraj(string el){
        LLNode<string>* pom = head;
        if(!prazna())
        {
            while(pom->next != NULL)
            {
                pom = pom->next;
            }
            LLNode<string>* temp = new LLNode<string>(el);
            pom->next = temp;
        }
    }

    string brisiSaPocetka(){
        if(prazna())
            throw exception();
        string el = head->info;
        LLNode<string>* pom = head;
        if(head->next == NULL)
            head = NULL;
        else
            head = head->next;
        delete pom;
        return el;
    }

    string brisiSaKraja(){
        string el;
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
            LLNode<string>* pom = head;
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
    
    LLNode<string>* pronadji(string el){
        if(prazna())
            throw exception();
        else if(head->info == el)
            return head;
        else
        {
            LLNode<string>* pom = head;
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

    LLNode<string>* uzmiHead() {return head;}

    LLNode<string>* uzmiSledeci(LLNode<string>* pom){
        if(pom->next == NULL)
            throw exception();
        return pom->next;
    }

    string uzmiSled(string el)
    {
        LLNode<string>* pom = pronadji(el);
        if (pom->next == NULL) {
            cout << "Element nema sledeci u listi" << endl;
            throw exception();
        }
        return pom->next->info;
    }

    string getHeadEl() { return head->info; }

    void stampaj(){
        if(!prazna())
        {
            for(LLNode<string>* pom = head; pom != NULL; pom = pom->next)
                cout << pom->print() << " ";
            cout << endl;
        }
    }

    bool uListi(string el){
        LLNode<string>* pom = head;
        while(pom->info != el && pom->next != NULL)
        {
            pom = pom->next;
        }
        if(pom->next == NULL)
            return false;
        return true;
    }

    void brisi(string el){
        LLNode<string>* pom = head;
        while(pom->next->info != el && pom->next->next != NULL)
        {
            pom = pom->next;
        }
        if(pom->next->next == NULL)
            throw exception();
        LLNode<string>* x = pom->next->next;
        delete pom->next;
        pom->next = x;
    }

};



