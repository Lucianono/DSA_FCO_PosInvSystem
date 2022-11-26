#include <iostream>
#include "SecuritySys.h"

using namespace std;
//this file is for Security (login) system

//List of Done
//create a username and password (will be decided by you)
//maximum of 3 tries ELSE terminates
//username and password variables SHOULD be  private(can't be accessed outside class)
//should login first before changing the username and password
//can change username and password

//List of work
//create function to GET username

//assigned to : Darwin Alba, Ramil Rosal

class Security
{
    private:
    string MuserL, MpassL, Mpass2; //modify
    string Cuser, Cpass;
    string Luser, Lpass;
    string Muser, Mpass;//modified user/pass
    int attempt = 0;
    int Choice;

    public:
    void Create() //creating account
    {
        cout<<"\nCreate an account"<< endl;

        cout<<"Please create a Username: ";
        cin >> Cuser;
        cout<<"Please create a Password: ";
        cin >> Cpass;

    }
    void Login()
    {
        cout << "\nLogin your account" << endl;
        cout<<"Please Enter your Username: ";
        cin >> Luser;
        cout<<"Please Enter your Password: ";
        cin >> Lpass;

        if(Luser == Cuser && Lpass == Cpass||Luser == Muser && Lpass==Mpass)
            {
                Content();
            }
        else
        {
            attempt = attempt +1;
            while(attempt < 3)
            {
                if (Luser != Cuser && Lpass == Cpass)
                {
                    cout << "your Username is incorrect."<< endl;
                    Login();
                }
                else if (Luser == Cuser && Lpass != Cpass)
                {
                    cout << "your Password is incorrect."<< endl;
                    Login();
                }
                else if (Luser != Cuser && Lpass != Cpass)
                {
                    cout << " This Account does not exist" << endl;
                    Login();
                }
            }
        }
        if(attempt==3)
        {
            cout << " This Account does not exist" << endl;
            cout << "Reached Maximum Tries... Closing Program"<< endl;
            exit(0);
        }
    }

    void Modify() //modify condition
    {
            cout<< "\n\nWELCOME\n"<< endl;
            cout << "SELECT FROM [1-3]" << endl;
            cout << "[1]Change Username" << endl;
            cout << "[2]Change Password" << endl;
            cout << "[3]LOGOUT and LOGIN Again" << endl;
            cout << "SO??: ";
            cin >> Choice;
            switch(Choice)
            {
                case 1:
                    {
                        cout<<"Enter new username: ";
                        cin >> Muser;
                        cout << "\nUSERNAME MODIFIED!\n"<< endl;
                        Luser=Muser;
                        Modify();
                    }
                case 2:
                    {
                        cout << "Enter new password: ";
                        cin >> Mpass;
                        cout << "\npassword modified\n"<< endl;
                        Lpass=Mpass;
                        Modify();
                    }
                case 3: Login(); break;
                default: cout <<"\nError Input...\n";
            }
    }

    void Content()
    {
        Modify();
    }
};

//this file is for Security (login) system
//create a username and password (will be decided by you)
//maximum of 3 tries ELSE terminates
//can change username and password
//should login first before changing the username and password
//username and password variables SHOULD be  private(can't be accessed outside class)
//create function to GET username
//assigned to : Darwin Alba, Ramil Rosal

SecuritySys::SecuritySys()
{
    int choice;
    cout<<"SecuritySys Class created"<<endl;
    Security push;
    push.Create();
    push.Login();

    cout << "\n\n";
}
