#ifndef INTHANDLER_H
#define INTHANDLER_H
#include <string>

using namespace std;


class IntHandler
{
    public:
        IntHandler();

        int intHandlerInput(string displayHint,int inputData);
        int intHandlerInput(string displayHint,int inputData,int a, int b);
    protected:

    private:
};

#endif // INTHANDLER_H
