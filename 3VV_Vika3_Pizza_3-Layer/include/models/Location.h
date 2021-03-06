#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using namespace std;

class Location
{
    public:
        static const int MAX_STRING_LENGTH = 24;
        static const int MAX_ADDRESS_LENGTH = 24;

        Location();

        int getIdNumber() const;
        string getName() const;
        string getAddress() const;
        bool getActiveState() const;

        void setIdNumber(int newIdNumber);
        void setName(string newName);
        void setAddress(string newAddress);
        void setActiveState(bool newState);

        friend istream&  operator >> (istream& in, Location& location);
        friend ostream&  operator << (ostream& out, const Location& location);

    private:

        int idNumber;
        char name[MAX_STRING_LENGTH];
        char address[MAX_ADDRESS_LENGTH];
        bool isActive;
};

#endif // LOCATION_H
