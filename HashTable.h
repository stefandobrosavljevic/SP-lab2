#pragma once
#include"HashObject.h"
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;


class HashTable
{
protected:
    unsigned int length = 0;
    unsigned int count = 0;

    unsigned int h(HashObject& obj){
        return (f(obj.getKey()) % length);
    }

    virtual unsigned int f(string s){
        unsigned int res = 0;
        unsigned int a = 7;
        for(int i = 0; s[i] != 0; i++)
            res = res * 31 + s[i];
        return res;
    } 

    virtual unsigned int g(unsigned int i){
        return (i + 1) % length;
    }

public:
    unsigned int getLength() {return length;}
    virtual double getLoadFactor(){
        return (double)count / (double)length;
    }
};

