#include "SuperRepo.h"

SuperRepo::SuperRepo()
{
    //ctor
}

SuperRepo::~SuperRepo()
{
    //dtor
}
///***************************************************************************************
/// Extra
int SuperRepo::getExtraLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open(".\\data\\Extras.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(Extra);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

Extra* SuperRepo::readExtraFile() {
    ifstream fin;
    Extra* masterList = 0;
    fin.open(".\\data\\Extras.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Extra);
            fin.seekg(0, fin.beg);

            masterList = new Extra[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(Extra)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToExtraFile(const Extra& extra) {
    ofstream fout;
    fout.open(".\\data\\Extras.dat", ios::binary|ios::app);
    fout.write((char*)(&extra), sizeof(extra));
    fout.close();
}

///***************************************************************************************
/// Location
int SuperRepo::getLocationLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open(".\\data\\Locations.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(Location);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

Location* SuperRepo::readLocationFile() {
    ifstream fin;
    Location* masterList = 0;
    fin.open(".\\data\\Locations.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Location);
            fin.seekg(0, fin.beg);

            masterList = new Location[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(Location)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToLocationFile(const Location& location) {
    ofstream fout;
    fout.open(".\\data\\Locations.dat", ios::binary|ios::app);
    fout.write((char*)(&location), sizeof(Location));
    fout.close();
}

///***************************************************************************************
/// ActiveOrder
int SuperRepo::getActiveOrderLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open(".\\data\\ActiveOrders.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(Order);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

Order* SuperRepo::readActiveOrderFile() {
    ifstream fin;
    Order* masterList = 0;
    fin.open(".\\data\\ActiveOrders.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Order);
            fin.seekg(0, fin.beg);
            //if(recordCount < 0) {
                masterList = new Order[recordCount];
                fin.read((char*)(masterList), (recordCount * sizeof(Order)));
            //} else {
            //    remove(".\\data\\ActiveOrders.dat");
            //}
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToActiveOrderFile(const Order& order) {
    ofstream fout;
    fout.open(".\\data\\ActiveOrders.dat", ios::binary|ios::app);
    fout.write((char*)(&order), sizeof(Order));
    fout.close();
}

void SuperRepo::writeAllButToActiveOrderFile(Order* order, int lineNr) {
    int lines = getActiveOrderLines();
    if(lines != 1) {
        ofstream fout;
        if(lineNr > 0) {
            fout.open(".\\data\\TempFile.dat", ios::binary|ios::app);
            fout.write((char*)(order), ((lineNr) * sizeof(Order)));
            fout.close();
        }
        if((lines - lineNr - 1) > 0) {
            fout.open(".\\data\\TempFile.dat", ios::binary|ios::app);
            fout.write((char*)(&order[lineNr + 1]), ((lines - lineNr - 1) * sizeof(Order)));
            fout.close();
        }
        remove(".\\data\\ActiveOrders.dat");
        rename(".\\data\\TempFile.dat", ".\\data\\ActiveOrders.dat");
    } else {
        remove(".\\data\\ActiveOrders.dat");
    }
}
void SuperRepo::writeAllToActiveOrderFile(Order* order) {
    ifstream fin;
    int recordCount = 0;
    fin.open(".\\data\\ActiveOrders.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(Order);
        //fin.seekg(0, fin.beg);
    }
    fin.close();
    ofstream fout;
    fout.open(".\\data\\ActiveOrders.dat", ios::binary);
    fout.write((char*)(order), (recordCount * sizeof(Order)));
    fout.close();
}

///***************************************************************************************
/// InactiveOrder
int SuperRepo::getInactiveOrderLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open(".\\data\\CompletedOrders.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(Order);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

Order* SuperRepo::readInactiveOrderFile() {
    ifstream fin;
    Order* masterList = 0;
    fin.open(".\\data\\CompletedOrders.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Order);
            fin.seekg(0, fin.beg);

            masterList = new Order[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(Order)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToInactiveOrderFile(const Order& order) {
    ofstream fout;
    fout.open(".\\data\\CompletedOrders.dat", ios::binary|ios::app);
    fout.write((char*)(&order), sizeof(Order));
    fout.close();
}

///***************************************************************************************
/// Pizza
int SuperRepo::getPizzaLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open(".\\data\\PizzaMenu.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(Pizza);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

Pizza* SuperRepo::readPizzaFile() {
    ifstream fin;
    Pizza* masterList = 0;
    fin.open(".\\data\\PizzaMenu.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Pizza);
            fin.seekg(0, fin.beg);

            masterList = new Pizza[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(Pizza)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToPizzaFile(const Pizza& pizza) {
    ofstream fout;
    fout.open(".\\data\\PizzaMenu.dat", ios::binary|ios::app);
    fout.write((char*)(&pizza), sizeof(Pizza));
    fout.close();
}

///***************************************************************************************
/// Sauce
int SuperRepo::getSauceLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open(".\\data\\PizzaSauce.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(PizzaSauce);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

PizzaSauce* SuperRepo::readSauceFile() {
    ifstream fin;
    PizzaSauce* masterList = 0;
    fin.open(".\\data\\PizzaSauce.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(PizzaSauce);
            fin.seekg(0, fin.beg);

            masterList = new PizzaSauce[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(PizzaSauce)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToSauceFile(const PizzaSauce& sauce) {
    ofstream fout;
    fout.open(".\\data\\PizzaSauce.dat", ios::binary|ios::app);
    fout.write((char*)(&sauce), sizeof(PizzaSauce));
    fout.close();
}

///***************************************************************************************
/// Size
int SuperRepo::getSizeLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open(".\\data\\PizzaSize.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(PizzaSize);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

PizzaSize* SuperRepo::readSizeFile() {
    ifstream fin;
    PizzaSize* masterList = 0;
    fin.open(".\\data\\PizzaSize.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(PizzaSize);
            fin.seekg(0, fin.beg);

            masterList = new PizzaSize[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(PizzaSize)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToSizeFile(const PizzaSize& size) {
    ofstream fout;
    fout.open(".\\data\\PizzaSize.dat", ios::binary|ios::app);
    fout.write((char*)(&size), sizeof(PizzaSize));
    fout.close();
}

///***************************************************************************************
/// Type
int SuperRepo::getTypeLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open(".\\data\\PizzaType.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(PizzaType);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

PizzaType* SuperRepo::readTypeFile() {
    ifstream fin;
    PizzaType* masterList = 0;
    fin.open(".\\data\\PizzaType.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(PizzaType);
            fin.seekg(0, fin.beg);

            masterList = new PizzaType[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(PizzaType)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToTypeFile(const PizzaType& type) {
    ofstream fout;
    fout.open(".\\data\\PizzaType.dat", ios::binary|ios::app);
    fout.write((char*)(&type), sizeof(PizzaType));
    fout.close();
}

///***************************************************************************************
/// Price
int SuperRepo::getPriceLines() const{
    ifstream fin;
    int recordCount = 0;
    fin.open(".\\data\\PriceList.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(PriceList);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

PriceList* SuperRepo::readPriceFile() {
    ifstream fin;
    PriceList* masterList = 0;
    fin.open(".\\data\\PriceList.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(PriceList);
            fin.seekg(0, fin.beg);

            masterList = new PriceList[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(PriceList)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToPriceFile(const PriceList& price) {
    ofstream fout;
    fout.open(".\\data\\PriceList.dat", ios::binary|ios::app);
    fout.write((char*)(&price), sizeof(PriceList));
    fout.close();
}

///***************************************************************************************
/// Topping
int SuperRepo::getToppingLines() const{
    ifstream fin;
    int recordCount = 0;
    fin.open(".\\data\\Toppings.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(Topping);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

Topping* SuperRepo::readToppingFile() {
    ifstream fin;
    Topping* masterList = 0;
    fin.open(".\\data\\Toppings.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Topping);
            fin.seekg(0, fin.beg);

            masterList = new Topping[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(Topping)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToToppingFile(const Topping& topping) {
    ofstream fout;
    fout.open(".\\data\\Toppings.dat", ios::binary|ios::app);
    fout.write((char*)(&topping), sizeof(Topping));
    fout.close();
}


