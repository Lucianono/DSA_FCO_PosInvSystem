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

//ADDITIONAL COMMENTS
//Syntax is working but not developer dynamic, should refer CLASS ON SEPERATE FILES on sololearn
//over info display when login failed, should instead check first for username if exists, then check if password is correct. No need to display ONLY THE USERNAME is wrong.
//password should re-input when changing password
//logging out should RESETS the login attempts
//theres variables that is unused
//CreateAccount is NOT necessary, but still good so don't delete
//the program itself should provide a username and password (ex. GlobeWifiAccount username:user password:tattoo@home)
//the program is running but can be improve


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
        cout<<"\nCREATE AN ACCOUNT"<< endl;
        cout<<"\nCreate a Username: ";
        cin >> Cuser;
        cout<<"Create a Password: ";
        cin >> Cpass;
        system ("CLS");
        //end of create
    }
    void Login()
    {
        cout << "LOG IN TO YOUR ACCOUNT" << endl;
        cout<<"\nEnter your Username: ";
        cin >> Luser;
        cout<<"Enter your Password: ";
        cin >> Lpass;
        //input ni user to log in
        if(Luser == Cuser && Lpass == Cpass||Luser == Muser && Lpass==Mpass)
            {
                system ("CLS");
                Content();
            }
        else
        {
            attempt = attempt +1;
            int i = 3;
            while(attempt < 3)
            {
                if (Luser != Cuser && Lpass == Cpass)
                {
                    system ("CLS");
                    cout << "Incorrect Username. ";
                    cout << "(" << i-attempt<< ")" << " Remaining Tries\n\n";
                    Login();
                }
                else if (Luser == Cuser && Lpass != Cpass)
                {
                    system ("CLS");
                    cout << "Incorrect Password. ";
                    cout << "(" << i-attempt<< ")" << " Remaining Tries\n\n";
                    Login();
                }
                else if (Luser != Cuser && Lpass != Cpass)
                {
                    system ("CLS");
                    cout << "Account does not Exist. ";
                    cout << "(" << i-attempt<< ")" << " Remaining Tries\n\n";
                    Login();
                }
            }
        }
        if(attempt==3)//test how about if else here for certain incorrect inputs?? 2 dar
        {
            cout << "\nReached Maximum Tries... Closing Program"<< endl;
            exit(0);
        }
    }

    void Modify() //modify condition
    {
            system ("CLS");
            cout<< "WELCOME "<< Luser << endl;
            cout << " " << endl;
            cout << "[1]Change Username" << endl;
            cout << "[2]Change Password" << endl;
            cout << "[3]LOGOUT and LOGIN Again" << endl;// dar great idea!!
            cout << "Enter Choice [1-3]: ";
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
                case 3: system("CLS");
                Login();
                break;
                default: cout <<"\nError Input...\n";
            }
    }

    void Content()
    {
        Modify();
    }
};


SecuritySys::SecuritySys()
{
    int choice;
    cout<<"SecuritySys Class created"<<endl;
    Security sc;
    sc.Create();
    sc.Login();

    cout << "\n\n";
}
