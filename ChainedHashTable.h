#include "HashTable.h"
#include "LList.h"
#include <iostream>
using namespace std;


template<class T, class R>
class ChainedHashTable : public HashTable<T, R>
{
protected:
    LList<HashObject<T, R>>* array;
public:
    ChainedHashTable(unsigned int len);

    ~ChainedHashTable();

    void insert(HashObject<T,R> obj);

    void withdraw(HashObject<T,R> obj);

    void withdraw(T key);

    HashObject<T,R> find(T key);
};


template<class T, class R>
ChainedHashTable<T, R>::ChainedHashTable(unsigned int len)
{
    this->length = len;
    this->count = 0;
    array = new LList<HashObject<T, R>>[len];
}


template<class T, class R>
ChainedHashTable<T, R>::~ChainedHashTable()
{
    HashObject<T, R> obj;
    for(unsigned int i = 0; i< this->length; i++){
        try{
            obj = array[i].getHeadEl();
            while(true){
               obj.deleteRecord();
               obj = array[i].uzmiSled(obj);
            }
        }
        catch(exception* e){}
    }
    delete array;
}


template<class T, class R>
HashObject<T, R> ChainedHashTable<T, R>::find(T key)
{
    HashObject<T,R> obj;
    unsigned int i = this->f(key) % this->length;
    obj = array[i].getHeadEl();
    while(!(obj.isEqualKey(key)))
        obj = array[i].uzmiSled(obj);
    return obj;
}


template<class T, class R>
void ChainedHashTable<T, R>::insert(HashObject<T,R> obj)
{
    array[this->h(obj)].dodajNaPocetak(obj);
    this->count++;
}


template<class T, class R>
void ChainedHashTable<T, R>::withdraw(HashObject<T,R> obj)
{
    array[h(obj)].brisi(obj);
    this->count--;
}


template<class T, class R>
void ChainedHashTable<T, R>::withdraw(T key)
{
    HashObject<T,R> obj = find(key);
    withdraw(obj);
}
