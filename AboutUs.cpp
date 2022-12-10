#include <iostream>
#include "AboutUs.h"

using namespace std;

AboutUs::AboutUs()
{

}

void AboutUs::displayMembers()
{
    ui.textCenter("--L E A D E R--",abtWidth);
    ui.textCenter("Calulo, Bryan Jett T.",abtWidth);
    cout<<endl;
    ui.textCenter("--M E M B E R S--",abtWidth);
    ui.textCenter("Alba, Darwin Iñigo I.",abtWidth);
    ui.textCenter("Baculi, Liah Francheska C.",abtWidth);
    ui.textCenter("Bernardo, Joel-Vincent G.",abtWidth);
    ui.textCenter("De Guzman, Michaela Andrei S.",abtWidth);
    ui.textCenter("Hernandez, Vince G.",abtWidth);
    ui.textCenter("Pascual, Andrei",abtWidth);
    ui.textCenter("Rebato, Jocelyn",abtWidth);
    ui.textCenter("Rosal, Ramil Angelo Jan M.",abtWidth);
    ui.textCenter("Senin, Benjamin B.",abtWidth);
    cout<<endl<<endl<<endl;
    ui.textCenter("We are students from Bulacan State University, currently taking Bachelor of Science",abtWidth);
    ui.textCenter("in Mathematics with Specialization in Computer Science, and in section BSM-CS 2A.",abtWidth);
    cout<<endl;
}

void AboutUs::displayAssignment()
{

    cout << "Create a set of structures and algorithms to display and modify a CICT Bookstore's point of sales and inventory system. \n"
        << "We decided that this will be done through object-oriented programming in C++ \n"
        << "The collaboration of the group was made possible by utilizing Git and GitHub itself in compiling codes. \n"
        << "Each member has a specific role to work on which is done through a virtual teams meeting and how the code was conceptualize.\n" ;

    cout<<endl;
    cout << "SUMMARY OF TASK DISTRIBUTION \n"
        << " ->> Main branch: Calulo \n"
        << " ->> UIDesign and AboutUs branch: De Guzman \n"
        << " ->> BookSystem and BookCRUD: Baculi, Bernardo, and Rebato \n"
        << " ->> SecuritySystem branch: Alba and Rosal \n"
        << " ->> OrderSystem and OrderCRUD branches: Hernandez and Pascual \n";

    cout<<endl;
}

void AboutUs::displayInstructor()
{
    ui.textCenter("Engr. Evelyn Samson",abtWidth);
    ui.textCenter("Faculty of CICT , currently instructing Data Structure and Algorithms and other computer-related subjects.",abtWidth);

    cout<<endl;
}


void AboutUs::displayAll(){
    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(7);

    ui.PageTitle("ABOUT US");
    displayMembers();

    ui.PageTitle("ABOUT THE PROJECT");
    displayAssignment();

    ui.PageTitle("INSTRUCTOR");
    displayInstructor();

    system("pause");
}
