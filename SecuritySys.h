#ifndef SECURITYSYS_H
#define SECURITYSYS_H
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

class SecuritySys
{
    private:
        string Duser= "user1";
        string Dpass= "pw123";
        string Cuser, Cpass;
        string Luser, Lpass;
        string Muser, Mpass;
        int i = 3; // tries
        int attempt = 0;
        int Choice;
    public:
        SecuritySys();
        bool Login();
        void Modify();

};

#endif // SECURITYSYS_H
