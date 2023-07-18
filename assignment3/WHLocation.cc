using namespace std;
#include "WHLocation.h"

int WHLocation::nextId = 1;

WHLocation::WHLocation(): Location(code, nextId){
    id = code+to_string(nextId++);
}

int WHLocation::getCapacity() const{
    return capacity;
}

bool WHLocation::add(string s, int n){
    if (this->isAvailable()){
        if (n <= capacity){
            product = s;
            quantity = n;
            return true;
        }
    }

    if (product == s){
        if (quantity + n <= capacity){
            quantity = quantity + n;
            return true;
        }
    }
    return false;
}

bool WHLocation::remove(int n){
    if (n > quantity){
        return false;
    }

    quantity = quantity - n;
    
    if (quantity == 0){
        product = NONE;
    }
    
    return true;
}

void WHLocation::print() const{
    cout<< "Location: " + id << endl;
    cout<< "Product: " + product << endl;
    cout<< "Quantity: " + to_string(quantity) << endl;
    cout<<""<<endl;
}