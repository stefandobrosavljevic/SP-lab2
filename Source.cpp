#include "ChainedScatterTable.h"
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main()
{
    ChainedScatterTable baza(1000000);
    
    //test za sinonime ***Radi***
    //baza.Register("www.com", "Stefan"); //pravi original
    //baza.Register("com.www", "Stefan"); //pravi sinonim
    //baza.Register("com.www", "Stefan"); //ne upisuje jer je isti kljuc
    //
    //baza.find("www.com"); //->pronadjen original
    //baza.find("com.www"); //->pronadjen sinonim
    //baza.find("asd"); //->nije pronadjen


    baza.Register("www.fakultet.edu.rs", "12345678");
    baza.Register("www.skola.edu.rs", "555111666771");
    baza.Register("www.trgovina.co.rs", "123123123");

    baza.Register("www.fakultet.edu.rs", "77777");

    cout << baza.WhoIs("www.fakultet.edu.rs") << endl;
    cout << baza.WhoIs("www.skola.edu.rs") << endl;



    return 0;
 }
