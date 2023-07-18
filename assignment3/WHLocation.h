#ifndef WHLOCATION_H
#define WHLOCATION_H

#include "defs.h"
#include "Location.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class WHLocation: public Location {

    public:
        WHLocation();
        virtual int getCapacity() const;
        virtual bool add(string, int);
        virtual bool remove(int);
        void print() const;

    private:
        const char code = 'B';
        const int capacity = WHLOC_CAPACITY;
        static int nextId;

};


#endif