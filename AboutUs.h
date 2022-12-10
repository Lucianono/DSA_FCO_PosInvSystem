#ifndef ABOUTUS_H
#define ABOUTUS_H
#include "UIDesign.h"


class AboutUs
{
    public:
        AboutUs();
        void displayMembers();
        void displayAssignment();
        void displayInstructor();
        void displayAll();

    protected:

    private:

        UIDesign ui;
        int abtWidth = 155;
};

#endif // ABOUTUS_H
