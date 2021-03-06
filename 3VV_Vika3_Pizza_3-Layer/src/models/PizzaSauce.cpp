#include "PizzaSauce.h"

PizzaSauce::PizzaSauce()
{
    idNumber = 0;
    name[0] = '\0';
    priceCategory = 0;
    active = false;
}

///******************************************************************************

int PizzaSauce::getIdNumber() const{
    return idNumber;
}

string PizzaSauce::getName() const{
    return name;
}

int PizzaSauce::getPriceCategory() const{
    return priceCategory;
}

bool PizzaSauce::getActiveState() const{
    return active;
}

///****************************************************

void PizzaSauce::setIdNumber(int newIdNumber) {
    idNumber = newIdNumber;
}

void PizzaSauce::setName(string newName) {
    strToCharArr(newName);
}

void PizzaSauce::setPriceCategory(int newPriceCatagory) {
    priceCategory = newPriceCatagory;
}

void PizzaSauce::setActiveState(bool newState) {
    active = newState;
}

/// Converts strings to a character array.
void PizzaSauce::strToCharArr(string nameStr) {
    for(unsigned int i = 0; i < nameStr.size(); i++) {
        if(i == MAX_STRING_LENGTH -1) {
            break;
        }
        this->name[i] = nameStr.at(i);
    }
    this->name[nameStr.size()] = '\0';                   // Adds the esc.character after the end of the string.
    this->name[MAX_STRING_LENGTH - 1] = '\0';         // Adds the esc.character to the end of the charArray.
}
