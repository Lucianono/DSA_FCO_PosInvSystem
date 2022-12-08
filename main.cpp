#include <iostream>
#include <windows.h>
#include <unistd.h>

#include "UIDesign.h"
#include "AboutUs.h"
#include "BookSys.h"
#include "SecuritySys.h"
#include "OrderSys.h"
#include "Book.h"
#include "IntHandler.h"


UIDesign ui;
AboutUs abt_us;
BookSys book;
SecuritySys security;
OrderSys order;
IntHandler ih;

HWND WINAPI GetConsoleWindowNT(void)
{
    //declare function pointer type
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    //declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;

    //get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    //assign proceedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib,TEXT("GetConsoleWindow"));

    //check if the function pointer is valid
    //since the function pointer is undocumented
    if(GetConsoleWindow == NULL)
    {
        return NULL;
    }
    //call the undocumented function
    return GetConsoleWindow();
}

void MainMenu()
{
    //variable declarations
    int opt;

    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(7);
    ui.PageTitle("Main Menu");
    cout << "[1] Order" << endl;
    cout << "[2] Book Inventory" << endl;
    cout << "[3] About" << endl;
    cout << "[4] Account" << endl;

    opt = ih.intHandlerInput("\n\nEnter Option: ", opt,4,1);

    switch (opt){
        case 1:
            order.orderMenu(book);
            break;
        case 2:
            book.bookMenu();
            break;
        case 3:
            //about func
            break;
        case 4:
            security.securityMenu();
            break;
    }


}


using namespace std;

int main()
{


    // Set console window height & width
    const int width = 1280;
    const int height = 720;

    HWND hWnd=GetConsoleWindowNT();
    //resize window and center to screen
    MoveWindow(hWnd, GetSystemMetrics(SM_CXSCREEN)/2 - width/2, GetSystemMetrics(SM_CYSCREEN)/2 - height/2, width, height, SWP_SHOWWINDOW);

    SetConsoleTitle("CICT Book Store");


    order.getOrder(book);

    bool isUserAuthorized = security.Login();
    while(isUserAuthorized){
        MainMenu();
    }



    return 0;
}
