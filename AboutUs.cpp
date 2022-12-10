#include <iostream>
#include "AboutUs.h"

using namespace std;

AboutUs::AboutUs()
{

}

void AboutUs::displayMembers()
{
    cout << "ABOUT US\n" << endl;

    cout << "\tLeader: \n";
    cout << "\tCalulo, Bryan Jett \n";
    cout << "\tMembers: \n";
    cout << "\tAlba, Darwin Inigo \n";
    cout << "\tBaculi, Liah Francheska \n";
    cout << "\tBernardo, Joel-Vincent \n";
    cout << "\tDe Guzman, Michaela Andrei \n";
    cout << "\tHernandez, Vince \n";
    cout << "\tPascual, Andrei \n ";
    cout << "\tRebato, Jocelyn \n";
    cout << "\tRosal, Ramil Angelo \n" << endl;

    cout << "We are students coming from Bulacan State University and who are also in their second year of studying BSM CS \n";
}

void AboutUs::displayAssignment()
{

    cout << "Project Assigned: Create a set of structures and algorithms to display and modify a CICT Bookstore's point of sales and inventory system. \n";
    cout << "This will be done through object-oriented programming in C++ \n";

    cout << "ASSIGNMENT" << endl;
    cout << "UI Design" << endl;
    cout << "About Us" << endl;
    cout << "Book System" << endl;
    cout << "Book CRUD" << endl;
    cout << "Security System" << endl;
    cout << "Order System" << endl;
    cout << "Order CRUD" << endl << endl;

    cout << "ABOUT THE PROJECT \n" << endl;
    cout << "The collaboration of the group was made possible by utilizing git and github itself in compiling codes." << endl;
    cout << "Each member has a specific role to work on which is done through a virtual teams meeting and how the code was conceptualize.\n" << endl;

    cout << "Summary of task distribution" << endl;
    cout << "Main branch: Calulo \n";
    cout << "UI Design branch: De Guzman \n";
    cout << "Book system, Book CRUD, and Development branches: Baculi, Bernardo, and Rebato \n";
    cout << "Security System branch: Alba and Rosal \n";
    cout << "Order System and Order CRUD branches: Hernandez and Pascual \n";
}

void AboutUs::displayInstructor()
{
    cout << "INSTRUCTOR \n" << endl;
    cout << "Engr. Evelyn Santos - Faculty of CICT , currently instructing Data Structure and Algorithms and other computer-related subjects. \n" << endl;
}


