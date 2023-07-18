
using namespace std;
#include "Location.h"

Location::Location(char c, int n){
    id = c + to_string(n);
    product = NONE;
}

string Location::getId() const{
    return id;
}

string Location::getProduct() const{
    return product;
}

int Location::getQuantity() const{
    return quantity;
}

bool Location::isEmpty() const{
    if (quantity == 0){
        return true;
    }
    return false;
}

bool Location::isAvailable() const{
    if (product == NONE){
        return true;
    }
    return false;
}

void Location::print() const{
    cout<< id + " " + product + " " + to_string(quantity) << endl;
}


