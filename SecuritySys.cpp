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

    ui.setTxtColor(7);

    int attempt = 0;

    for(int j = 0; j<i ; j++){
        system("CLS");
        ui.PageTitle("Login");

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
                    cout<<"\nPermission granted! \n";
                    system("pause");
                    return true;
                }
                else //incorrect pass
                {
                    cout << "Incorrect Password. ";
                    cout << "(" << i-attempt<< ")" << " Remaining Tries\n\n";
                    system("pause");
                }
            }
            else// wrong username
            {
                cout << "Account does not Exist. ";
                cout << "(" << i-attempt<< ")" << " Remaining Tries\n\n";
                system("pause");
            }
        }

        if(attempt==3)
        {
            if (Luser==Cuser || Luser == Duser) // correct username
            {
                if(Lpass == Cpass||Lpass==Dpass)//correct pass
                {
                    cout<<"\nPermission granted! \n";
                    system("pause");
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
void SecuritySys::securityMenu()
{
    bool menu_active = true;
    while(menu_active){

        system("CLS");
        ui.TitleHeader();
        ui.setTxtColor(7);
        ui.PageTitle("Security Menu");

        cout<< "\t WELCOME "<< Luser << endl;
        cout << endl;
        cout << "[1] Change Username" << endl;
        cout << "[2] Change Password" << endl;
        cout << "[3] Logout Account" << endl << endl;
        cout << "[0] Back" << endl << endl;
        Choice = ih.intHandlerInput("Enter Choice [1-3]: ", Choice, 3, 0);

        if (Choice == 1)
        {
            cout << "Enter your Current Username: ";
            cin >> Muser;
            if (Muser==Duser)
            {
                cout<<"Enter new username: ";
                cin >> Luser;
                cout << "USERNAME MODIFIED!\n"<< endl;
                Duser = Luser;
            }
            else
            {
                cout << "This is not your Current Username.\n\n";
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
                cout << "PASSWORD MODIFIED!\n\n";
                Dpass=Lpass;
            }
            else
            {
                cout << "This is not your Current Password.\n\n";
            }
        }
        else if (Choice == 3)
        {
            for (int j = 0; j < 3; j++) {
               cout << "\rLogging out, please wait   \rLogging out, please wait";
               for (int i = 0; i < 3; i++) {
                  cout << ".";
                  sleep(1);
               }
            }
            menu_active = false;
            Login ();
            break;
        }
        else if (Choice == 0)
        {
            menu_active = false;
            break;
        }

        system("pause");

    }

}
