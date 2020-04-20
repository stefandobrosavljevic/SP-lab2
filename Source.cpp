#includ "ChainedHashTable.h"
#include "User.h"
#include<bits/stdc++.h>
using namespace std;


int main()
{
    ChainedHashTable<char*, User> baza(10);
    int id;
    char ime[10], lozinka[10];
    User *pData;
    while(strcmp(ime, "izlaz") != 0){
        cin >> id;
        cin >> ime;
        cin >> lozinka;
        if(strcmp(ime, "izlaz") != 0){
            pData = new User(ime, lozinka);
            HashObject<char*, User> obj(ime, pData);
            baza.insert(obj);
        }
    }
    ime[0] = 'A';
    ime[1] = '\0';
    while (strcmp(ime, "izlaz") != 0) {
        cin>> ime;
        cin>> lozinka;
        pData= new User(ime, lozinka);
        HashObject<char*, User> obj1(ime, pData);
        HashObject<char*, User> obj2 = baza.find(obj1.getKey());
        if (obj1 == obj2) {
            cout<< "Korisnik";
            obj1.print();
            cout<< " je uspesno prijavljen!" << endl;
        }
         else {
             cout<< "Logovanje neuspesno" << endl;
         }
     }
     cout<< endl;
 }
