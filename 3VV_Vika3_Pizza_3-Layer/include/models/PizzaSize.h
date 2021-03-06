#ifndef PIZZASIZE_H
#define PIZZASIZE_H

#include <string>
using namespace std;

class PizzaSize
{
    public:
        static const int MAX_STRING_LENGTH = 24;
        PizzaSize();

        int getIdNumber() const;
        string getName() const;
        int getPriceCategory() const;
        double getToppingMult() const;
        double getToppingOffset() const;
        bool getActiveState() const;

        void setIdNumber(int newIdNumber);
        void setName(string newName);
        void setPriceCategory(int newPriceCategory);
        void setToppingMult(double newToppingMult);
        void setToppingOffset(double newToppingOffset);
        void setActiveState(bool newState);

        friend istream&  operator >> (istream& in, PizzaSize& size);
        friend ostream&  operator << (ostream& out, const PizzaSize& size);

    private:
        int idNumber;
        char name[MAX_STRING_LENGTH];
        int priceCategory;
        double toppingPriceMultiplyer;
        double toppingPriceOffset;
        bool isActive;

        void strToCharArr(string name);
};

#endif // PIZZASIZE_H
