#include<bits/stdc++.h>
using namespace std;
class User
{
    char* name;
    char* password;

public:
    User() {name = NULL; password = NULL;}
    User(char t[], char a[]){
        name = new char[strlen(t)];
        strcpy(name, t);
        password = new char[strlen(a)];
        strcpy(password, a);
    }
    void print(){
        cout << name << " | " << password << endl;
    }
};

