#include "ScatterObject.h"
#include <bits/stdc++.h>
using namespace std;


template<class T, class R>
class ChainedScatterObject : public ScatterObject<T, R>
{
public:
    long next;

    ChainedScatterObject() : ScatterObject<T, R>() {next = -1;}
    ChainedScatterObject(T k) : ScatterObject<T, R>(k) {next = -1;}
    ChainedScatterObject(T k, R* object) : ScatterObject<T, R>(k, object) {next = -1;}
    ChainedScatterObjext(T k, R* object, long n) : ScatterObject<T, R> (k, object) { next = n;}

};
