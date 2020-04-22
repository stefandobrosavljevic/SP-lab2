#pragma once
#include<iostream>
using namespace std;


class HashObject
{
protected:
    string key;
    string* record;

public:
    HashObject() { 
        //key = (T)0; 
        record = nullptr; }
    HashObject(string k) { key = k; record = NULL; }
    HashObject(string k, string record) 
    { 
        key = k; 
        this->record = new string();
        *(this->record) = record;
    }
    ~HashObject() {
        deleteRecord();
    }
    HashObject& operator = (HashObject const& obj) {
        key = obj.key;
        if (obj.record != nullptr)
        {
            record = new string();
            *record = *(obj.record);
        }
        else
            record = nullptr;
        return *this;
    }

    HashObject(const HashObject& obj) {
        key = obj.key;
        if (obj.record != nullptr)
        {
            record = new string();
            *record = *(obj.record);
        }
        else
            record = nullptr;
    }

    bool operator == (HashObject const& obj) {
        return *record == *(obj.record);
    }

    void deleteRecord() {
        if (record != NULL) {
            delete record;
            record = NULL;
        }
    }
    string getKey() { return key; }
    string* getRecord() { return record; }
    bool isEqualKey(string k) { return key == k; }
    void print() { cout << key << " | " << record; }
};


