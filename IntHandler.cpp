#include "IntHandler.h"
#include <iostream>
#include <limits>

using namespace std;

IntHandler::IntHandler()
{
    //ctor
}

//if input wrong this happens
int IntHandler::intHandlerInput(string displayHint,int inputData){
    while (cout << displayHint && !(cin >> inputData )) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "   -Invalid Input. Please try again.- \n";
        }
    return inputData;
}
int IntHandler::intHandlerInput(string displayHint,int inputData , int a, int b){
    while (cout << displayHint && !(cin >> inputData) || (inputData>a || inputData<b)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "   -Invalid Input. Please try again.- \n";
        }
    return inputData;
}

