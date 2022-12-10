#include <iostream>
#include "AboutUs.h"

using namespace std;

AboutUs::AboutUs()
{

}

void AboutUs::displayMembers()
{
    ui.textCenter("=== GROUP DATAISTS ===",abtWidth);
    cout<<endl;
    ui.textCenter("--L E A D E R--",abtWidth);
    ui.textCenter("Calulo, Bryan Jett T.",abtWidth);
    cout<<endl;
    ui.textCenter("--M E M B E R S--",abtWidth);
    ui.textCenter("Alba, Darwin Inigo I.",abtWidth);
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
        << "Each member has a specific role to work on which is done through a virtual teams meeting and how the code was conceptualize.\n"
        << "The program is created and tested in CodeBlocks 20.03 gcc 8.1.0 \n";

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

void AboutUs::displayMemberInformation()
{
    cout <<"-> Alba, Darwin Inigo I. \n"
        << "    - Maysantol, Bulakan, Bulacan \n"
        << "    - (+63)920-654-7790 \n"
        << "    - darwininigo.alba.i@bulsu.edu.ph \n" <<endl;

    cout <<"-> Baculi, Liah Francheska C. \n"
        << "    - Prenza 1, Marilao, Bulacan \n"
        << "    - (+63)939-736-0741 \n"
        << "    - liahfrancheska.baculi.c@bulsu.edu.ph \n" <<endl;

    cout <<"-> Bernardo, Joel-Vincent G. \n"
        << "    - Poblacion, Norzagaray, Bulacan \n"
        << "    - (+63)956-056-4142 \n"
        << "    - joelvincent.bernardo.g@bulsu.edu.ph \n" <<endl;

    cout <<"-> Calulo, Bryan Jett T. \n"
        << "    - Lawa, Meycauayan, Bulacan \n"
        << "    - (+63)915-112-0027 \n"
        << "    - bryanjett.calulo.t@bulsu.edu.ph \n" <<endl;

    cout <<"-> De Guzman, Michaela Andrei S. \n"
        << "    - Poblacion, Baliuag, Bulacan \n"
        << "    - (+63)967-594-2151 \n"
        << "    - michaelaandrei.deguzman.s@bulsu.edu.ph \n" <<endl;

    cout <<"-> Hernandez, Vince G. \n"
        << "    - Tuktukan, Guiginto, Bulacan \n"
        << "    - (+63)906-889-1508 \n"
        << "    - vince.hernandez.g@bulsu.edu.ph \n" <<endl;

    cout <<"-> Pascual, Andrei \n"
        << "    - Sta. Rita, Guiginto, Bulacan \n"
        << "    - (+63)935-350-5068 \n"
        << "    - andrei.pascual.x@bulsu.edu.ph \n" <<endl;

    cout <<"-> Rebato, Jocelyn \n"
        << "    - Mojon, Malolos, Bulacan \n"
        << "    - (+63)935-221-7533 \n"
        << "    - jocelyn.rebato.x@bulsu.edu.ph \n" <<endl;

    cout <<"-> Rosal, Ramil Angelo Jan M. \n"
        << "    - Dakila, Malolos, Bulacan \n"
        << "    - (+63)939-326-9501 \n"
        << "    - ramilangelojan.rosal.m@bulsu.edu.ph \n" <<endl;

    cout <<"-> Senin, Benjamin B. \n"
        << "    - Taal, Malolos, Bulacan \n"
        << "    - (+63)908-900-9407 \n"
        << "    - benjamin.senin.b@bulsu.edu.ph \n" <<endl;

    cout<<endl;
}


void AboutUs::displayAll(){
    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(7);

    ui.PageTitle("ABOUT US");
    displayMembers();
    system("pause");

    ui.PageTitle("ABOUT THE PROJECT");
    displayAssignment();
    system("pause");

    ui.PageTitle("INSTRUCTOR");
    displayInstructor();
    system("pause");

    ui.PageTitle("CONTACT INFORMATION");
    displayMemberInformation();
    system("pause");
}
