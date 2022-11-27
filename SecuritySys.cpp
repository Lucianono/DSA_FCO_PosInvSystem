#include <iostream>
#include "SecuritySys.h"
#include <conio.h>
#include <limits>

using namespace std;

//if input wrong this happens
int intHandlerInput(string displayHint,int inputData){
    while (cout << displayHint && !(cin >> inputData )) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "   -Invalid Input. Please try again.- \n";
        }
    return inputData;
}
int intHandlerInput(string displayHint,int inputData , int a, int b){
    while (cout << displayHint && !(cin >> inputData) || (inputData>a || inputData<b)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "   -Invalid Input. Please try again.- \n";
        }
    return inputData;
}


//Constructor
SecuritySys::SecuritySys()
{

}

//login method; return true if login success
bool SecuritySys::Login()
    {
        cout <<"\nYour Default Username is: " << Duser << endl;
        cout <<"Your Default Password is: " << Dpass << endl;

        cout << "\nLOG IN TO YOUR ACCOUNT" << endl;
        cout<<"\nEnter your Username: ";
        cin >> Luser;
        cout<<"Enter your Password: ";
        cin >> Lpass;

        attempt = attempt +1;
        int i = 3;

        if (Luser==Cuser || Luser == Duser)
        {
            if(Lpass == Cpass||Lpass==Dpass)
            {
                system ("CLS");
                attempt=0;
                cout<<"Permission granted! \n";
                return true;
            }
            else
                while (attempt < 3)
                    {
                        system ("CLS");
                        cout << "Incorrect Password. ";
                        cout << "(" << i-attempt<< ")" << " Remaining Tries\n\n";
                        attempt+1;
                        Login();
                    }
        }
            else
                {
                while (attempt < 3)
                    {
                        system ("CLS");
                        cout << "Account does not Exist. ";
                        cout << "(" << i-attempt<< ")" << " Remaining Tries\n\n";
                        attempt+1;
                        Login();
                    }
                }
            if(attempt==3)
                {
                    cout << "\nReached Maximum Tries... Closing Program"<< endl;
                    exit(0);

                }
    }

//change password function
void SecuritySys::Modify()
    {

            cout<< "WELCOME "<< Luser << endl;
            cout << " " << endl;
            cout << "[1]Change Username" << endl;
            cout << "[2]Change Password" << endl;
            cout << "[3]LOGOUT and LOGIN Again" << endl;
            Choice = intHandlerInput("Enter Choice [1-3]: ", Choice, 3, 1);
            switch(Choice)
            {
                case 1:
                    {
                        cout << "Enter your Current Username: ";
                        cin >> Muser;
                        if (Muser==Duser)
                            {
                                cout<<"Enter new username: ";
                                cin >> Luser;
                                system ("CLS");
                                cout << "USERNAME MODIFIED!\n"<< endl;
                                Duser = Luser;
                                Modify();
                            }
                        else
                        {
                            system("CLS");
                            cout << "This is not your Current Username.\n\n";
                            Modify();
                        }
                    }
                case 2:
                    {
                        cout << "Enter your Current Password: ";
                        cin >> Mpass;
                        if (Mpass == Dpass)
                            {
                                cout << "Enter new Password: ";
                                cin >> Lpass;
                                system ("CLS");
                                cout << "PASSWORD MODIFIED!\n\n";
                                Dpass=Lpass;
                                Modify();
                            }
                        else
                            {
                                system ("CLS");
                                cout << "This is not your Current Password.\n\n";
                                Modify();
                            }

                    }
                case 3:
                    {
                            system("CLS");
                            Login ();
                            break;
                    }

                default: cout << "\nError Input";
            }
        }





