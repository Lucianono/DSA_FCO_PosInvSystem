#include <iostream>
#include "BookSys.h"

using namespace std;

//this file is for the CICT Books System

//create a database for the given CICT books using 2D array
//should have 4 attributes: BookID, BookName, BookYear, Quantity
//let Quantity of each book be 20
//BookID will be decided by you, pick which is best
//the books is in Teams

//create a CRUD system for the Books
//should access the book by the given Book ID
//can modify the Quantity
//should NOT modify the BookID,Name,and Year
//notify if TotalBookQuantity is <= 5%

//assigned to : Joel-Vincent Bernardo, Jocelyn Rebato, Liah Baculi

BookSys::BookSys()
{
    cout<<"BookSys Class created"<<endl;
}
