#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Location{

    public:
        Location(char, int);
        string getId() const;
        string getProduct() const;
        int getQuantity() const;
        bool isEmpty() const;
        bool isAvailable() const;
        virtual int getCapacity() const = 0;
        virtual bool add(string, int) = 0;
        virtual bool remove(int) = 0;
        void print() const;

    protected:
        string id;
        string product;
        int quantity = 0;
        const string NONE = "Empty";
};
#endif