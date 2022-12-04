#include "SecuritySys.h"
#include <iostream>
#include <conio.h>
#include <unistd.h>

using namespace std;



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
    ui.TitleHeader();
    ui.setTxtColor(2);
    ui.PageTitle("Login");

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
        Choice = ih.intHandlerInput("Enter Choice [1-3]: ", Choice, 3, 1);

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
            for (int j = 0; j < 3; j++) {
               cout << "\rLogging out, please wait   \rLogging out, please wait";
               for (int i = 0; i < 3; i++) {
                  cout << ".";
                  sleep(1);
               }
            }
            Login ();
        }

    }
