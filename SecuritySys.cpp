#include <iostream>
#include "SecuritySys.h"
#include <conio.h>
#include <limits>

using namespace std;
//verify
//if input wrong this happens
int intHandlerInput(string displayHint,int inputData)
{
    while (cout << displayHint && !(cin >> inputData ))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "   -Invalid Input. Please try again.- \n";
        }
    return inputData;
}
int intHandlerInput(string displayHint,int inputData , int a, int b)
{
    while (cout << displayHint && !(cin >> inputData) || (inputData>a || inputData<b))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n -Invalid Input. Please try again.- \n";
        }
    return inputData;
}


//Constructor
SecuritySys::SecuritySys()
{

}

void SecuritySys::showHint(){
    cout <<"\nYour Default Username is: " <<Duser<< endl;
    cout <<"Your Default Password is: " <<Dpass<< endl;
}
//login method; return true if login success
bool SecuritySys::Login()
{
    int attempt = 0;

    for(int j = 0; j<i ; j++){
        cout << "\nLOG IN TO YOUR ACCOUNT" << endl;
        cout<<"\nEnter your Username: ";
        cin >> Luser;
        cout<<"Enter your Password: ";
        cin >> Lpass;

        attempt = attempt + 1;

        if (attempt < 3)
        {
            if (Luser==Cuser || Luser == Duser) // correct username
            {
                if(Lpass == Cpass||Lpass==Dpass)//correct pass
                {
                    system ("CLS");
                    cout<<"Permission granted! \n";
                    return true;
                }
                else //incorrect pass
                {
                    system ("CLS");
                    cout << "Incorrect Password. ";
                    cout << "(" << i-attempt<< ")" << " Remaining Tries\n\n";
                }
            }
            else// wrong username
            {
                system ("CLS");
                cout << "Account does not Exist. ";
                cout << "(" << i-attempt<< ")" << " Remaining Tries\n\n";
            }
        }

        if(attempt==3)
        {
            if (Luser==Cuser || Luser == Duser) // correct username
            {
                if(Lpass == Cpass||Lpass==Dpass)//correct pass
                {
                    system ("CLS");
                    cout<<"Permission granted! \n";
                    return true;
                }
                else //incorrect pass
                {
                    system ("CLS");
                    cout << "Incorrect Password. " << endl;
                    cout << "\nReached Maximum Tries... Closing Program"<< endl;
                    exit(0);
                }
            }
        else// wrong username
                {
                    system ("CLS");
                    cout << "Account does not Exist. " << endl;
                    cout << "\nReached Maximum Tries... Closing Program"<< endl;
                    exit(0);
                }
        }
    }


}
//change password function
void SecuritySys::Modify()
{

        cout<< "\nWELCOME "<< Luser << endl;
        cout << endl;
        cout << "\n[1]Change Username" << endl;
        cout << "[2]Change Password" << endl;
        cout << "[3]LOGOUT and LOGIN Again" << endl;
        Choice = intHandlerInput("Enter Choice [1-3]: ", Choice, 3, 1);

        if (Choice == 1)
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
        else if (Choice == 2)
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
        else if (Choice == 3)
        {
            system("CLS");
            Login ();
        }

    }
