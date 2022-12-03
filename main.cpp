#include <iostream>
#include <windows.h>

#include "UIDesign.h"
#include "AboutUs.h"
#include "BookSys.h"
#include "SecuritySys.h"
#include "OrderSys.h"
#include "Book.h"


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

using namespace std;

int main()
{

    UIDesign ui;
    AboutUs abt_us;
    BookSys book;
    SecuritySys security;
    OrderSys order;

    // Set console window height & width
    const int width = 1280;
    const int height = 720;

    HWND hWnd=GetConsoleWindowNT();
    //resize window and center to screen
    MoveWindow(hWnd, GetSystemMetrics(SM_CXSCREEN)/2 - width/2, GetSystemMetrics(SM_CYSCREEN)/2 - height/2, width, height, SWP_SHOWWINDOW);

    SetConsoleTitle("CICT Book Store");


    //

    book.printAllBooks();


    //

    cout << endl;
    cout << "Hello Dataists!" << endl;







    return 0;
}
