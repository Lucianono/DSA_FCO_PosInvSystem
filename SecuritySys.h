#ifndef SECURITYSYS_H
#define SECURITYSYS_H
#include "IntHandler.h"
#include "UIDesign.h"
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

class SecuritySys
{
    private:
        string Duser= "a";
        string Dpass= "a";
        string Cuser, Cpass;
        string Luser, Lpass;
        string Muser, Mpass;
        int i = 3; // tries
        int Choice;
    public:
        SecuritySys();
        IntHandler ih;
        UIDesign ui;
        void showHint();
        bool Login();
        void securityMenu();

};

#endif // SECURITYSYS_H
