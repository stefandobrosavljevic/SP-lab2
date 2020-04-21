#pragma once
#include"HashObject.h"
#include<iostream>
using namespace std;


class ScatterObject : public HashObject
{
public:
    int status; // 0-slobodan, 1-obrisan, 2-zauzet

    ScatterObject() : HashObject() {status = 0;}
    ScatterObject(string k) : HashObject (k) {status = 0;}
    ScatterObject(string k, string object) : HashObject(k, object) {status = 0;}


};
