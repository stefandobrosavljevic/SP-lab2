#include "HashObject.h"
#include "HashTable.h"
#include <bits/stdc++.h>
using namespace std;


template<class T, class R>
class ChainedHashTable : public HashTable<T, R>
{
protected:
    SLList<HashObject<T, R>>* array;
public:
    ChainedHashTable(unsigned int len){
        length = len;
        count = 0;
        array = new SLList<HashTable<T, R>>[lenght];
    }

    ~ChainedHashTable(){
        HashObject<T, R> obj;
        for(unsigned int i = 0; i<length; i++){
            try{
                obj = array[i].front();
                while(true){
                   obj.deleteRecord();
                   obj = array[i].getNextEl(obj);
                }
            }
            catch(exception* e){}
        }
        delete[] array;
   }

    void insert(HashObject<T,R> obj){
        array [h(obj)].addToHead(obj);
        count++;
    }
    void withdraw(HashObject<T,R> obj){
        array [h(obj)].deleteEl(obj);
        count--;
        }
    void withdraw(T key){
        HashObject<T,R> obj = find(key);
        withdraw(obj);
    }

    HashObject<T,R> find(T key){
        HashObject<T,R> obj;
        unsigned int i = f(key) % length;
        obj = array[i].getHeadEl();
        while(!(obj.isEqualKey(key)))
            obj = array[i].getNextEl(obj);
        return obj;
    }
};
