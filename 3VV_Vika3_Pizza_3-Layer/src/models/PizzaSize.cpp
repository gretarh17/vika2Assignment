#include "PizzaSize.h"

PizzaSize::PizzaSize() {
    idNumber = 0;
    name[0] = '\0';
    priceCategory = 0;
    toppingPriceMultiplyer = 1.0;
    toppingPriceOffset = 0.0;
    isActive = false;
}

///***************************************************************************************

int PizzaSize::getIdNumber() const{
    return idNumber;
}

string PizzaSize::getName() const{
    return name;
}

int PizzaSize::getPriceCategory() const{
    return priceCategory;
}
double PizzaSize::getToppingMult() const {
    return toppingPriceMultiplyer;
}

double PizzaSize::getToppingOffset() const {
    return toppingPriceOffset;
}

bool PizzaSize::getActiveState() const{
    return isActive;
}

///***************************************************************************************

void PizzaSize::setIdNumber(int newIdNumber) {
    idNumber = newIdNumber;
}

void PizzaSize::setName(string newName) {
    strToCharArr(newName);
}

void PizzaSize::setPriceCategory(int newPriceCategory) {
    priceCategory = newPriceCategory;
}

void PizzaSize::setToppingMult(double newToppingMult) {
    toppingPriceMultiplyer = newToppingMult;
}

void PizzaSize::setToppingOffset(double newToppingOffset) {
    toppingPriceOffset = newToppingOffset;
}

void PizzaSize::setActiveState(bool newState) {
    isActive = newState;
}

///***************************************************************************************
/// Converts strings to a character array.
void PizzaSize::strToCharArr(string nameStr) {
    for(unsigned int i = 0; i < nameStr.size(); i++) {
        if(i == MAX_STRING_LENGTH -1) {
            break;
        }
        this->name[i] = nameStr.at(i);
    }
    this->name[nameStr.size()] = '\0';              // Adds the esc.character after the end of the string.
    this->name[MAX_STRING_LENGTH - 1] = '\0';       // Adds the esc.character to the end of the charArray.
}

///***************************************************************************************

