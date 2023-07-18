#ifndef STORELOCATION_H
#define STORELOCATION_H

#include "defs.h"
#include "Location.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class StoreLocation: public Location{

    public:
        StoreLocation();
        void setProduct(string);
        int getFreeSpace() const;
        virtual int getCapacity() const;
        virtual bool add(string, int);
        virtual bool remove(int);
        void print() const;
    
    private:
        const char code = 'A';
        const int capacity = SLOC_CAPACITY;
        static int nextId;

};
#endif