#ifndef UIDESIGN_H
#define UIDESIGN_H

using namespace std;

class UIDesign
{
    public:
        UIDesign();
        void Login();
        void MainMenu();
        void AddBook();
        void ViewBook();
        void DeleteBook();
        void SearchBook();
        void OrderBook();
        void PrintReceipt();

        void setTxtColor(int ColorValue);
        void TitleHeader();
        void PageTitle(string title);
        bool sortAsc(string a, string b);
        bool sortDesc(string a, string b);
        int countDigit (long long n);
    protected:

    private:
};

#endif // UIDESIGN_H
