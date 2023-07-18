
using namespace std;
#include "StoreLocation.h"

int StoreLocation::nextId = 1;

StoreLocation::StoreLocation(): Location(code, nextId){
    id = code+to_string(nextId++);
}

void StoreLocation::setProduct(string s){
    product = s;
}

int StoreLocation::getFreeSpace() const{
    return capacity - quantity;
}

int StoreLocation::getCapacity() const{
    return capacity;
}

bool StoreLocation::add(string s, int n){
    if (product == s){
        if (quantity + n <= SLOC_CAPACITY){
            quantity = quantity + n;
            return true;
        }
    }
    if (product == NONE){
        if (n <= SLOC_CAPACITY){
            product = s;
            quantity = n;
        }
    }

    return false;
}

bool StoreLocation::remove(int n){
    if (n > quantity){
        return false;
    }
    quantity = quantity - n;
    return true;
}

void StoreLocation::print() const{
    cout<< "Location: " + id << endl;
    cout<< "Product: " + product << endl;
    cout<< "Quantity: " + to_string(quantity) << endl;
    cout<<""<<endl;
}