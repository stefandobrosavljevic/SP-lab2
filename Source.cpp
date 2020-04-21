#include "ChainedScatterTable.h"
#include "User.h"
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main()
{
    ChainedScatterTable baza(10);
    int id;
    string ime = "A";
    string lozinka;
    while(ime != "izlaz"){
        cout << "Unesite ime i lozinku" << endl;
        cin >> ime;
        cin >> lozinka;
        if(ime != "izlaz"){
            if (baza.Register(ime, lozinka))
                cout << "Uspesno!" << endl;
            else
                cout << "Neuspesno!" << endl;
        }
    }
    ime[0] = 'A';
    ime[1] = '\0';
    while (ime != "izlaz") {
        cin >> ime;
        cin >> lozinka;
        ChainedScatterObject obj1(ime, lozinka);
        ChainedScatterObject obj2 = baza.find(obj1.getKey());
        if (obj2.getRecord() != nullptr) {
            cout<< "Korisnik ";
            obj1.print();
            cout<< " je uspesno prijavljen!" << endl;
        }
         else {
             cout<< "Logovanje neuspesno" << endl;
         }
     }
     cout<< endl;

     return 0;
 }
