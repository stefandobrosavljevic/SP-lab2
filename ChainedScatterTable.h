#pragma once
#include"HashTable.h"
#include"ChainedScatterObject.h"
#include<iostream>
using namespace std;


class ChainedScatterTable : public HashTable
{
protected:
    ChainedScatterObject * array;
    //LList<ChainedScatterObject>* sinonimi;

public:
    ChainedScatterTable(unsigned int len){
        this->length = len;
        this->count = 0;
        array = new ChainedScatterObject[len];
    }

    ~ChainedScatterTable() {
        delete[] array;
    }

    void insert(ChainedScatterObject& obj){
        if(this->count == this->getLength())
            throw new exception("the table is full");
        long probe = this->h(obj);
        if(array[probe].status == 2)
        {
            while(array[probe].next != -1)
                probe = array[probe].next;
            long tail = probe;
            probe = this->g(probe);
            while(array[probe].next != -1 && probe != tail)
                probe = this->g(probe);
            if(probe == tail)
                throw new exception("Poor secondary transf");
            array[tail].next = probe;
        }
        array[probe] = obj;
        array[probe].status = 2;
        array[probe].next = -1;
        this->count++;
    }

    ChainedScatterObject find(string key){
        long probe = this->f(key) % this->length;
        while(probe != -1) //probe != -1
        {
            if(!array[probe].isEqualKey(key)) //.isEqualKey(key)
                probe = array[probe].next;
            else
                return array[probe];
        }
        ChainedScatterObject obj;
        return obj;
    }

    void withdraw(string key){
        if (this->count == 0)
            throw new exception("Table is empty");
        long probe = this->f(key) % this->length;
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
                array[nextEl] = ChainedScatterObject();
                array[nextEl].status = 1; // obrisan
            }
        }
        this->count--;
    }

    string WhoIs(string domain) {
        ChainedScatterObject obj = find(domain);
        if (obj.getRecord() != nullptr)
            return *(obj.getRecord());


        return "NULL";
    }

    bool Register(string domain, string ID)
    {
        if (this->WhoIs(domain) == "NULL")
        {
            ChainedScatterObject obj(domain, ID);
            this->insert(obj);
            return true;
        }
        return false;
    }

};
