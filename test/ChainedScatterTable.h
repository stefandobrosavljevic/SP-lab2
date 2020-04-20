#include"HashTable.h"
#include<bits/stdc++.h>
using namespace std;


template<class T, class R>
class ChainedScatterTable : public HashTable<T, R>
{
protected:
    ChainedScatterObject<T, R> * array;

public:
    ChainedScatterTable(unsigned int len){
        length = len;
        count = 0;
        array = new ChainedScatterTable<T, R>[len];
    }

    ~ChainedScatterTable() {delete[] array;}

    void insert(ChainedScatterObject<T, R> obj){
        if(count == getLength())
            throw new exception("the table is full");
        long probe = h(obj);
        if(!array[probe].free){
            while(array[probe].next != -1)
                probe = array[probe].next;
            long tail = probe;
            probe = g(probe);
            while(!array[probe].free && probe != tail)
                probe = g(probe);
                if(probe == tail)
                    throw new exception("Poor secondary transf");
                array[tail].next = probe;
        }
        array[probe] = obj;
        array[probe].status = 2;
        array[probe].next = -1;
        count++;
    }

    ChainedScatterObject<T, R> find(T key){
        long probe = f(key) % length;
        while(probe != -1){
            if(!array[probe]isEqual(key))
                probe = array[probe].next;
            else
                return array[probe];
        }
        throw new exception("ELement not found");
    }

    void withdraw(T key){
        if (count == 0)
            throw new SBPException("Table is empty");
        long probe = f(key)%length;
        long prev = -1;
        while (probe != -1 && !array[probe].isEqualKey(key)){
            prev = probe;
            probe = array[probe].next;
        }
        if (probe == -1)
            throw new exception("Element not found!");
        if( prev != -1) {
            // brise se sinonim
            array[prev].next = array[probe].next;
            array[probe].deleteRecord();
            array[probe].status = 1; // obrisan
        }
        else{
            if(array[probe].next == -1){
                array[probe].deleteRecord();
                array[probe].status = 1; // obrisan
            }
            else{
                long nextEl = array[probe].next;
                array[probe].deleteRecord();
                array[probe] = array[nextEl];
                array[probe].next = array[nextEl].next;
                array[nextEl] = ChainedScatterObject<T,R>();
                array[nextEl].status = 1; // obrisan
            }
        }
        count--;
    }
};
