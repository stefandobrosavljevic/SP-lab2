#include"HashObject.h"
#include<bits/stdc++.h>
using namespace std;

template<class T, class R>
class ScatterObject : public HashObject<T, R>
{
public:
    int status;

    ScatterObject() : HashObject<T, R>() {status = 0;}
    ScatterObject(T k) : HashObject<T, R> (k) {status = 0;}
    ScatterObject(T k, R* object) : HashObject<T, R>(k) {status = 0;}
   
};
