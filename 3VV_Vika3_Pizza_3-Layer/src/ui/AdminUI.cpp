#include "AdminUI.h"

AdminUI::AdminUI() {
    //ctor
}

void AdminUI::startUp() {
    char c;

    while(c != 'q') {
        cout << "Please select an admin option:" << endl;
        cout << "1)\t" << "Order menu" << endl;
        cout << "2)\t" << "Pizza menu" << endl;
        cout << "3)\t" << "Price category" << endl;
        cout << "4)\t" << "Pizza topping" << endl;
        cout << "5)\t" << "Extra" << endl;
        cout << "6)\t" << "Pizza size" << endl;
        cout << "7)\t" << "Pizza sauce" << endl;
        cout << "8)\t" << "Pizza base" << endl;
        cout << "9)\t" << "Location" << endl;
        cout << "q)\t" << "Go back" << endl;

        cin >> c;
               if (c == '1') {
            system("CLS");
            orderOptions();
        } else if (c == '2') {
            system("CLS");
            pizzaOptions();
        } else if (c == '3') {
            system("CLS");
            PriceOptions();
        } else if (c == '4') {
            system("CLS");
            toppingOptions();
        } else if (c == '5') {
            system("CLS");
            extraOptions();
        } else if (c == '6') {
            system("CLS");
            sizeOptions();
        } else if (c == '7') {
            system("CLS");
            sauceOptions();
        } else if (c == '8') {
            system("CLS");
            baseOptions();
        } else if (c == '9') {
            system("CLS");
            locationOptions();
        }
    }
    system("CLS");
}

/// Specials
void AdminUI::orderOptions() {
    char c;
    while(c != 'q') {
        cout << "Order options" << endl;
        cout << "1)\t" << "Display active orders" << endl;
        cout << "2)\t" << "Display inactive orders" << endl;
        cout << " )\t" << "......................." << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
               if (c == '1') {
            system("CLS");
            //addOrders();
            displayActiveOrders();
        } else if (c == '2') {
            system("CLS");
            //editOrders();
            displayInactiveOrders();
        } else if (c == '3') {
            //displaySpecialsOrders();
        }
    }
    system("CLS");
}
void AdminUI::displayActiveOrders() {
    Order* InactiveOrderList = dataBase.activeOrderMaster;
    int lines = adminService.repo.getInactiveOrderLines();
    Location* locList = dataBase.locationMaster;

    for(int i = 0; i < lines; i++) {
        cout << "Order ID: " << InactiveOrderList[i].getOrderId() << endl;
        cout << "Pizzas in current order: " << endl;
        for(int j = 0; j < InactiveOrderList[0].MAX_PIZZAS_ORDER; j++) {
            if(InactiveOrderList[i].getPizzas()[j].getName() != "") {
                cout << (j + 1) << ")  " << InactiveOrderList[i].getPizzas()[j].getName() << endl;
            } else if(InactiveOrderList[i].getPizzas()[j].getSauce().getIdNumber() != 0) {
                cout << (j + 1) << ")  Custom pizza" << endl;
            }
        }
        cout << "Extras in current order: " << endl;
        for(int j = 0; j < InactiveOrderList[0].MAX_EXTRAS_ORDER; j++) {
            if(InactiveOrderList[i].getExtras()[j].getName() != "") {
                cout << (j + 1) << ")  " << InactiveOrderList[i].getExtras()[j].getName() << endl;
            }
        }
        if(InactiveOrderList[i].isDelivered()) {
            cout << "Deliver to: " << InactiveOrderList[i].getAddress() << endl;
            cout << "Total price: " << orderService.getPrice(InactiveOrderList[i]) << endl;
            if(InactiveOrderList[i].getPaymentStatus()) {
                cout << "Payment status: Payed" << endl;
            } else {
                cout << "Payment status: Payed at delivery" << endl;
            }
        } else {
            cout << "Pickup at: " << locList[InactiveOrderList[i].getLocationId() - 1].getAddress() << endl;
            cout << "Name or phone: " << InactiveOrderList[i].getAddress() << endl;
            cout << "Total price: " << orderService.getPrice(InactiveOrderList[i]) << endl;
            if(InactiveOrderList[i].getPaymentStatus()) {
                cout << "Payment status: Payed" << endl;
            } else {
                cout << "Payment status: Payed at delivery" << endl;
            }
        }
        if(InactiveOrderList[i].getComment() != "") {
            cout << "Comment: " << InactiveOrderList[i].getComment() << endl;
        }
    }
}
void AdminUI::displayInactiveOrders() {
    Order* InactiveOrderList = dataBase.inactiveOrderMaster;
    int lines = adminService.repo.getInactiveOrderLines();
    Location* locList = dataBase.locationMaster;

    for(int i = 0; i < lines; i++) {
        cout << "Order ID: " << InactiveOrderList[i].getOrderId() << endl;
        cout << "Pizzas in current order: " << endl;
        for(int j = 0; j < InactiveOrderList[0].MAX_PIZZAS_ORDER; j++) {
            if(InactiveOrderList[i].getPizzas()[j].getName() != "") {
                cout << (j + 1) << ")  " << InactiveOrderList[i].getPizzas()[j].getName() << endl;
            } else if(InactiveOrderList[i].getPizzas()[j].getSauce().getIdNumber() != 0) {
                cout << (j + 1) << ")  Custom pizza" << endl;
            }
        }
        cout << "Extras in current order: " << endl;
        for(int j = 0; j < InactiveOrderList[0].MAX_EXTRAS_ORDER; j++) {
            if(InactiveOrderList[i].getExtras()[j].getName() != "") {
                cout << (j + 1) << ")  " << InactiveOrderList[i].getExtras()[j].getName() << endl;
            }
        }
        if(InactiveOrderList[i].isDelivered()) {
            cout << "Deliver to: " << InactiveOrderList[i].getAddress() << endl;
            cout << "Total price: " << orderService.getPrice(InactiveOrderList[i]) << endl;
            if(InactiveOrderList[i].getPaymentStatus()) {
                cout << "Payment status: Payed" << endl;
            } else {
                cout << "Payment status: Payed at delivery" << endl;
            }
        } else {
            cout << "Pickup at: " << locList[InactiveOrderList[i].getLocationId() - 1].getAddress() << endl;
            cout << "Name or phone: " << InactiveOrderList[i].getAddress() << endl;
            cout << "Total price: " << orderService.getPrice(InactiveOrderList[i]) << endl;
            if(InactiveOrderList[i].getPaymentStatus()) {
                cout << "Payment status: Payed" << endl;
            } else {
                cout << "Payment status: Payed at delivery" << endl;
            }
        }
        if(InactiveOrderList[i].getComment() != "") {
            cout << "Comment: " << InactiveOrderList[i].getComment() << endl;
        }
    }
}

/// Pizza menu
void AdminUI::pizzaOptions() {
    char c;
    while(c != 'q') {
        cout << "Pizza menu options" << endl;
        cout << "1)\t" << "Add a pizza to the menu" << endl;
        //cout << "2)\t" << "Edit a pizza in the menu" << endl;
        cout << "3)\t" << "Display pizza menu" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
               if (c == '1') {
            system("CLS");
            addPizzas();
            system("CLS");
        } else if (c == '2') {
            system("CLS");
            //editPizzas();
            system("CLS");
        } else if (c == '3') {
            system("CLS");
            displayPizzaMenu();
        }
    }
    system("CLS");
}
void AdminUI::displayPizzaMenu() {
    Pizza* pizzaList = dataBase.pizzaMaster;
    if(pizzaList != 0) {
        cout << "Pizzas in current menu: " << endl;
        for (int i = 0; i < adminService.repo.getPizzaLines(); i++) {
            cout << pizzaList[i].getIdNumber();
            cout << ")\t" << /* setw(pizzaList[0].MAX_PIZZA_LENGTH) << left << */ pizzaList[i].getName() << endl;
            cout << "\t  " << /* setw(pizzaList[0].getSize().MAX_STRING_LENGTH) << left << */ setw(9) << pizzaList[i].getSize().getName();
            cout << " | " << /* setw(pizzaList[0].getType().MAX_STRING_LENGTH) << left << */ pizzaList[i].getType().getName() + " base";
            cout << " | " << /* setw(pizzaList[0].getSauce().MAX_STRING_LENGTH) << left << */ pizzaList[i].getSauce().getName() + " sauce" << endl;
            cout << "\t  " << "Toppings: | ";
            for(int j = 0; j < pizzaList[0].MAX_TOPPINGS_PIZZA; j++) {
                if(pizzaList[i].getToppings()[j].getIdNumber() != 0) {
                    cout << pizzaList[i].getToppings()[j].getName() << " | ";
                }
            }
            cout << endl;
            cout << "\t  " << "Price:    | " << pizzaService.getPrice(pizzaList[i]) << "kr | Is ";
            if(pizzaList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }

            cout << endl;
        }
    }
}
void AdminUI::addPizzas() {
    Pizza pizza;
    char userInput;
    string nameInput;
    double totalPrice = 0.0;
    int sizeSelection;
    int typeSelection;
    int sauceSelection;
    int toppingSelection[pizza.MAX_TOPPINGS_PIZZA];
    for(int i = 0; i < pizza.MAX_TOPPINGS_PIZZA; i++) {
        toppingSelection[i] = 0;
    }
    bool valid;
    do {
        system("CLS");
        dataBase.refreshPizza();
        displayPizzaMenu();
        cout << "Add a Pizza: " << endl;
        do{
            cout << "Enter pizza name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                validate.validateName(nameInput,valid);
            } catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        displaySizes();
        do {
            cout << "Select size: ";
            cin >> sizeSelection;
            validate.isInt(sizeSelection);
            try {
                validate.validateSizeSelection(sizeSelection, valid);
            } catch(InvalidSizeException) {
                cout <<"Invalid size Selection" << endl;
            }
        } while(!valid);
        displayBases();
        do {
            cout << "Select Base: ";
            cin >> typeSelection;
            validate.isInt(typeSelection);
            try {
                validate.validateTypeSelection(typeSelection, valid);
            } catch(InvalidTypeException) {
                cout <<"Invalid type Selection." << endl;
            }
        } while(!valid);
        displaySauces();
        do {
            cout << "Select sauce: ";
            cin >> sauceSelection;
            validate.isInt(sauceSelection);
            try {
                validate.validateSauceSelection(sauceSelection, valid);
            } catch(InvalidSauceException) {
                cout << "Invalid sauce Selection." << endl;
            }
        } while(!valid);
        displayToppings();
        valid = false;
        cout << endl << "Choose toppings: ";
        int counter = 0;
        int tempToppingSelection;
        cout << "Select toppings, press 0 to stop." << endl;

        while(counter < pizza.MAX_TOPPINGS_PIZZA) {
            toppingSelection[counter] = 0;
            cin >> tempToppingSelection;
            validate.isInt(tempToppingSelection);
            if(tempToppingSelection == 0) {
                break;
            }
            try {
                validate.validateToppingSelection(tempToppingSelection, valid);
            } catch(InvalidToppingException) {
                cout << "Invalid topping input." << endl;
            }
               toppingSelection[counter] = tempToppingSelection;
               counter++;
        }
        pizza = adminService.addPizza(nameInput, sizeSelection, typeSelection, sauceSelection, toppingSelection, totalPrice);
        cout << pizzaService.getPrice(pizza) << "kr" << endl;
        cout << "Set fixed price? (y/n) ";
        cin >> userInput;
        if(userInput == 'y') {
            valid = false;
            do {
                cin >> totalPrice;
                validate.isDouble(totalPrice);
                try {
                    validate.validatePrice(totalPrice, valid);
                } catch(InvalidPriceException) {
                    cout << "Invalid Price, try again." << endl;
                }
            } while(!valid);
            pizza.setTotalPrice(totalPrice);
        }
        adminService.SavePizza(pizza);
        dataBase.refreshPizza();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
    system("CLS");
}

/// Price Category
void AdminUI::PriceOptions() {
    char c;
    while(c != 'q') {
        cout << "Price options" << endl;
        cout << "1)\t" << "Add a price category" << endl;
        //cout << "2)\t" << "Edit a price category" << endl;
        cout << "3)\t" << "Display price categories" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
               if (c == '1') {
            addPriceCategory();
        } else if (c == '2') {
            //editPriceCategory();
        } else if (c == '3') {
            displayPriceCategory();
        }
    }
    system("CLS");
}
void AdminUI::displayPriceCategory() {
    dataBase.refreshPrice();
    PriceList* priceList = dataBase.priceMaster;
    if(priceList != 0) {
        cout << "Price categories in current list: " << endl;
        for (int i = 0; i < adminService.repo.getPriceLines(); i++) {
            cout << priceList[i].getIdNumber();
            cout << ")\t" << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[i].getName();
            cout << " | " << setw(5) << right << priceList[i].getPrice() << "kr | ";
            if(priceList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addPriceCategory() {
    char userInput;
    string nameInput;
    double PriceInput;
    bool valid;
    do {
        system("CLS");
        displayPriceCategory();
        cout << "Add a price category:" << endl;

          do{
            cout << "Enter prize category name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                validate.validateName(nameInput,valid);
            }
            catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        do{
            cout << "Enter category price:     ";
            cin >> PriceInput;
            validate.isDouble(PriceInput);
            try {
                validate.validatePrice(PriceInput, valid);
            } catch(InvalidPriceException) {
                cout << "Invalid price input." << endl;
            }
        } while(!valid);
        adminService.addPriceCategory(nameInput, PriceInput);
        dataBase.refreshPrice();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
}


/// Topping
void AdminUI::toppingOptions() {
    char c;
    while(c != 'q') {
        DataBase dataBase;
        system("CLS");
        cout << "Topping options" << endl;
        cout << "1)\t" << "Add a topping" << endl;
        //cout << "2)\t" << "Edit a topping" << endl;
        cout << "3)\t" << "Display a toppings" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            system("CLS");
            addToppings();
        } else if (c == '2') {
            //editToppings();
        } else if (c == '3') {
            displayToppings();
        }
    }
    system("CLS");
}
void AdminUI::displayToppings() {
    Topping* toppingList = dataBase.toppingMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(toppingList != 0) {
        cout << "Toppings in current list: " << endl;
        for (int i = 0; i < adminService.repo.getToppingLines(); i++) {
            cout << toppingList[i].getIdNumber();
            cout << ")\t" << setw(toppingList[0].MAX_STRING_LENGTH) << left << toppingList[i].getName();
            cout << " | " << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[toppingList[i].getPriceCategory()-1].getName();
            cout << " | " << setw(4) << right << (priceList[toppingList[i].getPriceCategory()-1].getPrice() * dataBase.sizeMaster[0].getToppingMult()) + dataBase.sizeMaster[0].getToppingOffset() << "kr | ";
            if(toppingList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addToppings() {
    char userInput;
    string nameInput;
    int priceCatInput;
    bool valid;
    do {
        system("CLS");
        displayToppings();
        cout << "Add a topping: " << endl;
        do{
            cout << "Enter topping name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                validate.validateName(nameInput, valid);
            } catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        displayPriceCategory();
        do{
            cout << "Select price category:    ";
            cin >> priceCatInput;
            validate.isInt(priceCatInput);
            try {
                validate.validatePriceCategory(priceCatInput, valid);
            } catch(InvalidPriceCategoryException) {
                cout << "Invalid price input." << endl;
            }
        } while(!valid);
        adminService.addTopping(nameInput, priceCatInput);
        dataBase.refreshTopping();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
    system("CLS");
}
/*
void AdminUI::editToppings() {
    int userSelection;
    char userInput;
    string newNameInput;
    int newPriceInput;
    bool newStateInput;
    bool valid;
    Topping* toppingList = dataBase.toppingMaster;
    displayToppings();

    do {
        cout << "Select topping: ";
        cin >> userSelection;
        valid = false;
        validate.isInt(userSelection, valid);
        if(userSelection != 0) {
            validate.validateToppingSelection(userSelection, valid);
        }
    } while(!valid);
    do{
        cout << "Enter new topping name: ";
        cin >> ws;
        getline(cin, newNameInput);
        valid = false;
        validate.validateName(newNameInput, valid);
    } while(!valid);
    displayPriceCategory();
    do {
        cout << "Select a new price category: ";
        cin >> newPriceInput;
        valid = adminService.validatePriceCategory(newPriceInput);
    } while(!valid);
    while(true) {
        cout << "Is active? (y/n) ";
        cin >> userInput;
        if(userInput == 'y' || userInput == 'Y') {
            newStateInput = true;
            break;
        } else if(userInput == 'n' || userInput == 'N') {
            newStateInput = false;
            break;
        }
    }
    adminService.editTopping((toppingList[userInput - 1].getIdNumber()), newNameInput, newPriceInput, newStateInput);
    dataBase.refreshTopping();
    system("CLS");
}
*/


/// Extras
void AdminUI::extraOptions() {
    char c;
    while(c != 'q') {
        system("CLS");
        cout << "Extra options" << endl;
        cout << "1)\t" << "Add a extra" << endl;
        //cout << "2)\t" << "Edit a extra" << endl;
        cout << "3)\t" << "Display extras" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
               if (c == '1') {
            system("CLS");
            addExtras();
        } else if (c == '2') {
            //editExtras();
        } else if (c == '3') {
            system("CLS");
            displayExtras();
        }
    }
    system("CLS");
}
void AdminUI::displayExtras() {
    Extra* extraList = dataBase.extraMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(extraList != 0) {
        cout << "Extras in current list: " << endl;
        for (int i = 0; i < adminService.repo.getExtraLines(); i++) {
            cout << extraList[i].getIdNumber();
            cout << ")\t" << setw(extraList[0].MAX_STRING_LENGTH) << left << extraList[i].getName();
            cout << " | " << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[extraList[i].getPriceCategory()-1].getName();
            cout << " | " << setw(4) << right << priceList[extraList[i].getPriceCategory()-1].getPrice() << "kr | ";
            if(extraList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addExtras() {
    char userInput;
    string nameInput;
    int priceInput;
    bool valid;
    do {
        system("CLS");
        displayExtras();
        cout << "Add an extra: " << endl;
        do{
            cout << "Enter extra name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                validate.validateName(nameInput,valid);
            } catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        displayPriceCategory();
        do{
            cout << "Select price category:    ";
            cin >> priceInput;
            validate.isInt(priceInput);
            try {
                validate.validatePriceCategory(priceInput, valid);
            } catch(InvalidPriceCategoryException) {
                cout << "Invalid price input." << endl;
            }
        } while(!valid);
        adminService.addExtra(nameInput, priceInput);
        dataBase.refreshExtra();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
    system("CLS");
}



/// Size
void AdminUI::sizeOptions() {
    char c;
    while(c != 'q') {
        cout << "Size options" << endl;
        cout << "1)\t" << "Add a size" << endl;
        //cout << "2)\t" << "Edit a size" << endl;
        cout << "3)\t" << "Display sizes" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
               if (c == '1') {
            system("CLS");
            addSize();
        } else if (c == '2') {
            //editSize();
        } else if (c == '3') {
            system("CLS");
            displaySizes();
        }
    }
    system("CLS");
}
void AdminUI::displaySizes() {
    PizzaSize* sizeList = dataBase.sizeMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(sizeList != 0) {
        cout << "Sizes in current list: " << endl;
        for (int i = 0; i < adminService.repo.getSizeLines(); i++) {
            cout << sizeList[i].getIdNumber();
            cout << ")\t" << setw(sizeList[0].MAX_STRING_LENGTH) << left << sizeList[i].getName();
            cout << " | " << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[sizeList[i].getPriceCategory()-1].getName();
            cout << " | " << setw(4) << right << priceList[sizeList[i].getPriceCategory()-1].getPrice() << "kr | ";
            if(sizeList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addSize() {
    char userInput;
    string nameInput;
    int priceInput;
    double toppingMult;
    double toppingOffset;
    bool valid;
    do {
        system("CLS");
        displaySizes();
        cout << "Add a pizza size: " << endl;
        do{
            cout << "Enter size name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                validate.validateName(nameInput, valid);
            } catch(InvalidNameException) {
                cout << "Invalid name input." << endl;
            }
        } while(!valid);
        displayPriceCategory();
        do{
            cout << "Select price category:    ";
            cin >> priceInput;
            validate.isInt(priceInput);
            try {
                validate.validatePriceCategory(priceInput,valid);
            } catch(InvalidPriceCategoryException) {
                cout << "Invalid price input." << endl;
            }
        } while(!valid);
        do {
            cout << "Enter topping price Multiplier: ";
            cin >> toppingMult;
            validate.isDouble(toppingMult);
            try {
                validate.validateMult(toppingMult, valid);
            } catch(InvalidMultException) {
                cout << "Invalid multiplier input." << endl;
            }
        } while(!valid);
        do {
            cout << "Enter topping price offset: ";
            cin >> toppingOffset;
            validate.isDouble(toppingOffset);
            try {
                validate.validatePrice(toppingOffset, valid);
            } catch(InvalidPriceException) {
                cout << "Invalid Offset input." << endl;
            }
        } while(!valid);
        adminService.addSize(nameInput, priceInput, toppingMult, toppingOffset);
        dataBase.refreshSize();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');

}



/// Sauce
void AdminUI::sauceOptions() {
    char c;
    while(c != 'q') {
        cout << "Sauce options" << endl;
        cout << "1)\t" << "Add a sauce" << endl;
        //cout << "2)\t" << "Edit a sauce" << endl;
        cout << "3)\t" << "Display sauces" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            system("CLS");
            addSauces();
        } else if (c == '2') {
            //editSauces();
        } else if (c == '3') {
            system("CLS");
            displaySauces();
        }
    }
    system("CLS");
}
void AdminUI::displaySauces() {
    PizzaSauce* sauceList = dataBase.sauceMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(sauceList != 0) {
        cout << "Sauces in current list: " << endl;
        for (int i = 0; i < adminService.repo.getSauceLines(); i++) {
            cout << sauceList[i].getIdNumber();
            cout << ")\t" << setw(sauceList[0].MAX_STRING_LENGTH) << left << sauceList[i].getName();
            cout << " | " << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[sauceList[i].getPriceCategory()-1].getName();
            cout << " | " << setw(4) << right << priceList[sauceList[i].getPriceCategory()-1].getPrice() << "kr | ";
            if(sauceList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addSauces() {
    char userInput;
    string nameInput;
    int priceInput;
    bool valid;
    do {
        system("CLS");
        displaySauces();
        cout << "Add a sauce: " << endl;
        do {
            cout << "Enter sauce name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                validate.validateName(nameInput,valid);
            } catch(InvalidNameException) {
                cout << "Invalid name input." << endl;
            }
        } while(!valid);
        displayPriceCategory();
        do{
            cout << "Select price category:    ";
            cin >> priceInput;
            validate.isInt(priceInput);
            try {
                validate.validatePriceCategory(priceInput,valid);
            } catch(InvalidPriceCategoryException) {
                cout << "Invalid price input." << endl;
            }
        } while(!valid);

        adminService.addSauce(nameInput, priceInput);
        dataBase.refreshSauce();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
    system("CLS");
}


/// Base
void AdminUI::baseOptions() {
    char c;
    while(c != 'q') {
        cout << "Pizza base options" << endl;
        cout << "1)\t" << "Add a base" << endl;
        //cout << "2)\t" << "Edit a base" << endl;
        cout << "3)\t" << "Display bases" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            system("CLS");
            addBase();
        } else if (c == '2') {
            //editBase();
        } else if (c == '3') {
            system("CLS");
            displayBases();
        }
    }
    system("CLS");
}
void AdminUI::displayBases() {
    PizzaType* typeList = dataBase.typeMaster;
    if(typeList != 0) {
        cout << "Bases in current list: " << endl;
        for (int i = 0; i < adminService.repo.getTypeLines(); i++) {
            cout << typeList[i].getIdNumber();
            cout << ")\t" << setw(typeList[0].MAX_STRING_LENGTH) << left << typeList[i].getName();
            cout << " | " << setw(4) << right << typeList[i].getPriceOffset() << "kr | ";
            if(typeList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addBase() {
    char userInput;
    string nameInput;
    double priceInput;
    bool valid;
    do {
        system("CLS");
        displayBases();
        cout << "Add a pizza base: " << endl;
        do {
            cout << "Enter base name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                validate.validateName(nameInput,valid);
            } catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        do {
            cout <<"Enter a price offset: ";
            cin >> priceInput;
            validate.isDouble(priceInput);
            try {
                validate.validatePrice(priceInput, valid);
            } catch(InvalidPriceException) {
                cout << "Invalid offset." << endl;
            }
        } while(!valid);

        adminService.addType(nameInput, priceInput);
        dataBase.refreshType();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
    system("CLS");
}


/// Location
void AdminUI::locationOptions() {
    char c;
    while(c != 'q') {
        cout << "Location options" << endl;
        cout << "1)\t" << "Add a location" << endl;
        //cout << "2)\t" << "Edit a location" << endl;
        cout << "3)\t" << "Display locations" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            system("CLS");
            addLocation();
        } else if (c == '2') {
            //editLocation();
        } else if (c == '3') {
            system("CLS");
            displayLocations();
        }
    }
    system("CLS");
}
void AdminUI::displayLocations() {
    Location* locList = dataBase.locationMaster;
    if(locList != 0) {
        cout << "Locations in current list: " << endl;
        for (int i = 0; i < adminService.repo.getLocationLines(); i++) {
            cout << locList[i].getIdNumber();
            cout << ")\t" << setw(locList[0].MAX_STRING_LENGTH) << left << locList[i].getName();
            cout << " | " << setw(locList[0].MAX_ADDRESS_LENGTH) << left << locList[i].getAddress();
            cout << " | ";
            if(locList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addLocation() {
    char userInput;
    string nameInput;
    string addressInput;
    bool valid;
    do {
        system("CLS");
        displayLocations();
        cout << "Add a location: " << endl;
        do {
            cout << "Enter location name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                validate.validateName(nameInput,valid);
            } catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        do {
            cout << "Enter address: ";
            cin >> ws;
            getline(cin, addressInput);
            try {
                validate.validateName(addressInput,valid);
            } catch(InvalidNameException) {
                cout <<"Invalid address input." << endl;
            }
        } while(!valid);
        adminService.addLocation(nameInput, addressInput);
        dataBase.refreshLocation();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
    system("CLS");
}
