#pragma once
#include"HashTable.h"
#include"ChainedScatterObject.h"
#include<iostream>
using namespace std;


class ChainedScatterTable : public HashTable
{
protected:
    ChainedScatterObject* array;
    ChainedScatterObject* sinonimi;

public:
    ChainedScatterTable(unsigned int len){
        this->length = len;
        this->count = 0;
        array = new ChainedScatterObject[len];
        sinonimi = new ChainedScatterObject[len];
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
            if (sinonimi[probe].status == 2) {
                while(sinonimi[probe].next != -1)
                    probe = sinonimi[probe].next;
                long tail = probe;
                probe = this->g(probe);
                while (sinonimi[probe].next != -1 && probe != tail)
                    probe = this->g(probe);
                if (probe == tail)
                    throw new exception("Poor secondary transf");
                sinonimi[tail].next = probe;

            }
            sinonimi[probe] = obj;
            sinonimi[probe].status = 2;
            sinonimi[probe].next = -1;
            this->count++;
            return;
           
        }
        array[probe] = obj;
        array[probe].status = 2;
        array[probe].next = -1;
        this->count++;
    }

    ChainedScatterObject find(string key){
        long probe = this->f(key) % this->length;
        if (!array[probe].isEqualKey(key)) {
            while (probe != -1) 
            {
                if (!sinonimi[probe].isEqualKey(key))
                    probe = sinonimi[probe].next;
                else {
                    cout << "Pronadjen sinonim " << key << endl;
                    return sinonimi[probe];
                }
            }
        }
        else {
            cout << "Pronadjen original " << key << endl;
            return array[probe];
        }
        cout << "Nije pronadjen " << key << endl;
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
            array[prev].next = array[probe].next;
            array[probe].deleteRecord();
            array[probe].status = 1;
        }
        else{
            if(array[probe].next == -1){
                array[probe].deleteRecord();
                array[probe].status = 1;
            }
            else{
                long nextEl = array[probe].next;
                array[probe].deleteRecord();
                array[probe] = array[nextEl];
                array[probe].next = array[nextEl].next;
                array[nextEl] = ChainedScatterObject();
                array[nextEl].status = 1;
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
            cout << "Uspesno registrovanje: " << domain << endl;
            return true;
        }

        cout << "Neuspesno registrovanje: " << domain << endl;
        return false;
    }

};
