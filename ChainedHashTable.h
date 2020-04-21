#include "HashTable.h"
#include "LList.h"
#include <iostream>
using namespace std;


class ChainedHashTable : public HashTable
{
protected:
    LList<HashObject>* array;
public:
    ChainedHashTable(unsigned int len);

    ~ChainedHashTable();

    void insert(HashObject obj);

    void withdraw(HashObject obj);

    void withdraw(string key);

    HashObject find(string key);
};



ChainedHashTable::ChainedHashTable(unsigned int len)
{
    this->length = len;
    this->count = 0;
    array = new LList<HashObject>[len];
}



ChainedHashTable::~ChainedHashTable()
{
    HashObject obj;
    for(unsigned int i = 0; i< this->length; i++){
        try{
            obj = array[i].getHeadEl();
            while(true){
               obj.deleteRecord();
               obj = array[i].uzmiSled(obj);
            }
        }
        catch(exception* e){
            e->what();
        }
    }
    delete[] array;
}



HashObject ChainedHashTable::find(string key)
{
    HashObject obj;
    unsigned int i = this->f(key) % this->length;
    obj = array[i].getHeadEl();
    while(!(obj.isEqualKey(key)))
        obj = array[i].uzmiSled(obj);
    return obj;
}



void ChainedHashTable::insert(HashObject obj)
{
    array[this->h(obj)].dodajNaPocetak(obj);
    this->count++;
}



void ChainedHashTable::withdraw(HashObject obj)
{
    array[h(obj)].brisi(obj);
    this->count--;
}



void ChainedHashTable::withdraw(string key)
{
    HashObject obj = find(key);
    withdraw(obj);
}
