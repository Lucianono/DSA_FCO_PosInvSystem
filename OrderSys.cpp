

//this file is for POS or (Order/Sale) System
//create a blank database for the orders using linked list
//should have the following attributes: OrderID, CustomerName, [BooksOrdered, QtyOrder] , UnitPrice, AmountPrice, VAT,
// ->>if the customer will pay by cash, add these attribute : Cash, Change
// ->>if the customer will pay by installment, add these attribute : 1stInstallment, 1stChange, 2ndInstallment, 2ndChange
//create your own OrderID format
//OrderId should be automated, every order should increment ID by 1, example Ord-01 -> Ord-02 -> Ord-03 ->...
//customer's first middle last name is NOT necessary, only the provided name, example Bryan Calulo, REYSAN, Luciano123, etc.
//customer CAN order 1 or more books
//BooksOrdered should linked to BookID in Book System
//BooksOrdered should be in 2D array together with the QtyOrder
//UnitPrice is 200.00
//AmountPrice is UnitPrice*TotalQtyOrder
//VAT is 12% of AmountPrice
//DiscountPrice is 5% of AmountPrice IF TotalQtyOrder is >= 3 ELSE 0
//TotalSales is AmountPrice + VAT - DiscountPrice
//Cash will be given by an imaginary customer
//Cash should decline IF Cash < TotalSales
//Change = Cash - TotalSales
//1stInstallment should be 60% of TotalSales ELSE decline
//2ndInstallment should be the the remaining balance ELSE decline
//assigned to : Vince Hernandez, Andrei Pascual


//create a CRUD system for the Order Database
//should create an Order Entry every transaction
//Customer paying with cash should differ from customer paying with installment
//ask if the customer will pay in cash or installment
//order should not complete IF QtyOrder > Quantity in Book System
//every order should decrement the Book quantity
//create function to display the customer with remaining balance
//create function to display the entire Order Database
//create function to read or access every attributes given

//ADDITIONAL COMMENTS
//main function SHOULD NOT BE HERE
//Syntax Structure is wrong(try building this project, it produces an errors)
//make use of classes of SEPERATE FILES refer on sololearn
//editRecords is not necessary
//Linked list is correct but needs improvement
//UI is not necessary
//Attributes is incomplete
//COMMENTING IS NECESSARY for others to read

#include <iostream>
#include <conio.h>

using namespace std;

	struct OrderSystem
	{
		int OrderID;
		string CustomerName;
		string Books;
		int Price;

		OrderSystem *next;
		OrderSystem *prev;
		OrderSystem *temp;
	};

OrderSystem *createOrder(OrderSystem *head, int OrderID, string CustomerName, int Price);
void userRecords(OrderSystem *head);
void editRecords(OrderSystem *head, int OrderID);
OrderSystem *addDummyRecords(OrderSystem *head);
OrderSystem *adminMenu(OrderSystem *head);

int main()
{

		OrderSystem *head;
		head = NULL;

		head = addDummyRecords(head);
		head = adminMenu(head);


	getch();
	return 0;
}

OrderSystem *adminMenu(OrderSystem *head)
{

	bool menu_active = true;
	while(menu_active)
	{


		int choice;

		cout << "\t--------------------------------------------\n";
		cout << "\t\t    -- Admin Menu -- \n";
		cout << "\t--------------------------------------------\n";
		cout << "\t[1] Display Order Records\n";
		cout << "\t[2] Edit Order Records\n";
		cout << "\n\t--------------------------------------------\n";
		cout << "\tEnter Choice: ";
		cin >> choice;
		cout << endl;

		switch(choice)
		{
			case 1:
				userRecords(head);
				break;
			case 2:
				int editID;
				cout << "\t--------------------------------------------\n";
				cout << "\tEnter Desired OrderID to Edit: ";
				cin >> editID;
				cout << "\n\t--------------------------------------------\n";
				editRecords(head, editID);
				break;
		}
	}

	return head;
}

void userRecords(OrderSystem *head)
{

		OrderSystem *displayPointer;
		displayPointer=head;
			cout << "\n\t--------------------------------------------\n";
			cout << "\t\t\t User Records \t\t\n";
			cout << "\t--------------------------------------------\n";
		while(displayPointer)
		{
			cout << "\tOrderID: " << displayPointer->OrderID << endl;
			cout << "\tCustomerName: " << displayPointer->CustomerName << endl;
			cout << "\tPrice: " << displayPointer->Price << endl;
			displayPointer=displayPointer->next;
			cout << "\t--------------------------------------------\n";
		}

		int choice;
		cout << "\t--------------------------------------------\n";
		cout << "\t\t  -- User Records Menu --\n";
		cout << "\t--------------------------------------------\n";
		cout << "\t[1] Edit Records\n";
		cout << "\t[2] Back\n";
		cout << "\n\t--------------------------------------------\n";
		cout << "\tEnter Choice: ";
		cin >> choice;
		cout << endl;

		switch(choice)
		{
			case 1:
				int editID;
				cout << "\t--------------------------------------------\n";
				cout << "\tEnter Desired OrderID to Edit: ";
				cin >> editID;
				cout << "\n\t--------------------------------------------\n";
				editRecords(head, editID);
				break;
			case 2:
				break;
			case 4:
				break;
		}

}

OrderSystem *createOrder(OrderSystem *head, int OrderID, string CustomerName, int Price)
{
	if(head==NULL)
	{
		OrderSystem *newUser;
		newUser = new OrderSystem;
		newUser->OrderID = OrderID;
		newUser->CustomerName = CustomerName;
		newUser->Price = Price;
		newUser->next=NULL;
		newUser->prev=NULL;
		head=newUser;
		head->temp = head;

		return head;

	}else
	{
		OrderSystem *newUser;
		newUser = new OrderSystem;
		newUser->OrderID = OrderID;
		newUser->CustomerName = CustomerName;
		newUser->Price = Price;
		newUser->next=NULL;
		newUser->prev=head->temp;
		head->temp->next = newUser;
		head->temp = head->temp->next;
		return head;
	}

}

void editRecords(OrderSystem *head, int OrderID)
{



	OrderSystem *displayPointer;
	displayPointer = head;

	while(displayPointer)
	{
		if (displayPointer->OrderID == OrderID)
		{
			cout << "\t--------------------------------------------\n";
			cout << "\t\t   -- Order Records Menu --\n";
			cout << "\t--------------------------------------------\n";
			cout << "\tCurrent OrderID: " << displayPointer->OrderID << "\tCurrent CustomerName: " << displayPointer->CustomerName<< endl;
			cout << "\t--------------------------------------------\n";
			cout << "\tOrderID: " << displayPointer->OrderID << endl;
			cout << "\tCustomerName: " << displayPointer->CustomerName << endl;
			cout << "\tPrice: " << displayPointer->Price << endl;
			cout << "\t--------------------------------------------\n";
			int choice;
			cout << "\t\t\t-- Options --\n";
			cout << "\t--------------------------------------------\n";
			cout << "\t[1] Edit CustomerName\t [2] Edit Books\n";
			cout << "\t[3] Edit Price \t [4] Exit\n";
			cout << "\t--------------------------------------------\n";
			cout << "\tAction: ";
			cin >> choice;
			cout << "\t--------------------------------------------\n";
			switch(choice)
			{
				case 1:

					cout << "\tCurrent CustomerName: " << displayPointer->CustomerName << endl;
					cout << "\tDesired CustomerName: ";
					getline(cin >> ws, displayPointer->CustomerName);
					break;
				case 2:
					cout << "\tCurrent Books: " << displayPointer->Books << endl;
					cout << "\tDesired Books: ";
					getline(cin >> ws, displayPointer->Books);
					break;
				case 3:
					cout << "\tCurrent Price: " << displayPointer->Price << endl;
					cout << "\tDesired Price: ";
					cin >> displayPointer->Price;
					break;
				case 4:
					break;
			}

			break;
			cout << "TEST";
		}
		displayPointer=displayPointer->next;
	}

	getch();

}

OrderSystem *addDummyRecords(OrderSystem *head)
{
		head = createOrder(head, 0, "Math", 0);
		createOrder(head, 1, "Science", 1000);
		createOrder(head, 2, "Calculus", 1000);
		createOrder(head, 3, "General Math", 600);
		createOrder(head, 4, "History", 500);
		createOrder(head, 5, "Programming", 600);

		return head;
}
