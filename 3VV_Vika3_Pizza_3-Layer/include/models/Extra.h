#ifndef EXTRA_H
#define EXTRA_H

#include <string>
using namespace std;

class Extra
{
    public:
        static const int MAX_STRING_LENGTH = 24;

        Extra();

        int getIdNumber() const;
        string getName() const;
        int getPriceCategory() const;
        bool getActiveState() const;

        void setIdNumber(int newIdNumber);
        void setName(string newName);
        void setPriceCategory(int newPriceCategory);
        void setActiveState(bool newState);
        void addExtra(Extra newExtra);

        friend istream&  operator >> (istream& in, Extra& extra);
        friend ostream&  operator << (ostream& out, const Extra& extra);

    private:


        int idNumber;
        char name[MAX_STRING_LENGTH];
        int priceCategory;
        bool isActive;

        void strToCharArr(string name);

};

#endif // EXTRA_H
