#pragma once
#include "ScatterObject.h"
#include <iostream>
using namespace std;



class ChainedScatterObject : public ScatterObject
{
public:
    long next;

    ChainedScatterObject() : ScatterObject() {next = -1;}
    ChainedScatterObject(string k) : ScatterObject(k) {next = -1;}
    ChainedScatterObject(string k, string object) : ScatterObject(k, object) {next = -1;}
    ChainedScatterObject(string k, string object, long n) : ScatterObject (k, object) { next = n;}

};
