#ifndef UIDESIGN_H
#define UIDESIGN_H

using namespace std;

class UIDesign
{
    public:
        UIDesign();

        void setTxtColor(int ColorValue);
        void TitleHeader();
        void PageTitle(string title);
        bool sortAsc(string a, string b);
        bool sortDesc(string a, string b);
        int countDigit (long long n);
        void textCenter(string title,int decorLength);
    protected:

    private:
};

#endif // UIDESIGN_H
