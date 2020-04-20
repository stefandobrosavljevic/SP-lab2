#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class User
{
    char* name;
    char* password;

public:
    User() {name = NULL; password = NULL;}

    ~User() {}

    User(char t[], char a[]){
        name = new char[strlen(t)];
        strcpy(name, t);
        password = new char[strlen(a)];
        strcpy(password, a);
    }

    User(const User& user) {
        name = new char[strlen(user.name)];
        strcpy(name, user.name);
        password = new char[strlen(user.password)];
        strcpy(password, user.password);
    }

    const User& operator = (const User& user) {
        name = new char[strlen(user.name)];
        strcpy(name, user.name);
        password = new char[strlen(user.password)];
        strcpy(password, user.password);
        return *this;
    }

    bool operator == (const User& user) {
        return strcmp(name, user.name) == 0 &&
            strcmp(password, user.password) == 0;
    }


    void print(){
        cout << name << " | " << password << endl;
    }
};

