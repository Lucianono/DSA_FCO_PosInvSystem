#include <iostream>
#include "SecuritySys.h"

using namespace std;
//this file is for Security (login) system

//List of Done
//create a username and password (will be decided by you)
//maximum of 3 tries ELSE terminates
//username and password variables SHOULD be  private(can't be accessed outside class)

//List of work
//can change username and password
//should login first before changing the username and password
//create function to GET username
//create username and password

//assigned to : Darwin Alba, Ramil Rosal

class Security
{
    private:
    string Cuser, Cpass;
    string Luser, Lpass;
    string Muser, Mpass;//modified user/pass
    int attempt = 0;
    string Choice;

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
        attempt = attempt +1;

        if(Luser == Cuser && Lpass == Cpass)
            {
                cout<< "Welcome"<< endl;
                Security push;
                push.Modify();
            }
        else
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
            if(attempt==3)
            {
                cout << "\nInvalid login attempts for 3 times... closing program"<< endl;
                exit(0);
            }


    }

    void ModifyCon() //modify condition
    {
        if(Choice == "y"|| Choice=="Y")
        {
            int C; //choice
            string MuserL, MpassL, Mpass2;
            cout << "\nLogin your account" << endl;
            cout<<"Please Enter your Username: ";
            cin >> MuserL;
            cout<<"Please Enter your Password: ";
            cin >> MpassL;

            if(MuserL == Cuser && MpassL == Cpass)
            {
                cout << "what do you want to Change";
                cout << "[1]Username";
                cout << "[2]Password";
                switch(C)
                {
                    case 1:
                        {
                            cout<<"Enter new username: ";
                            cin >> Muser;
                            cout << "username modified";
                            Luser==Muser;
                            Modify();
                        }
                    case 2:
                        {
                            cout << "Enter new password";
                            cin >> Mpass;
                            cout << "verify new password";
                            cin >>Mpass2;
                            if(Mpass2 == Mpass)
                            {
                                cout << "password modified";
                                Lpass==Mpass;
                            }
                            else
                                {
                                    cout << "password does not match... try again..." << endl;
                                }
                        }
                }
            }
            else
                cout <<"\nThis Account does not exist! try again...";

        }

        else if(Choice == "N"|| Choice=="n")
        {
            cout << "So you already have an account bruh";
            Login();
        }
        else
        {
            cout << "Invalid input... try again.";
            Modify();
        }
    }

    void Modify()
    {
        cout<< "Do you want to change your acc?" << endl;
        cout << "if yes, type [Y] or [y] and if no type [N] or [n]: ";
        cin >> Choice;
        ModifyCon();
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


    cout << "\n\n\n";


}
