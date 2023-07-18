
#include "Store.h"

using namespace std;

Store::Store(const string& n){
    name = n;
    StoreLocation slocs[SLOCS];
	WHLocation wlocs[WHLOCS];
    products = new List();
}

Store::~Store(){
}

void Store::findAvailableSLoc(StoreLocation** sloc){
    int i = 0;
    for (; i<SLOCS; i++){
        if (slocs[i].isAvailable()){
            break;
        }
    }
    *sloc = &slocs[i];
}

void Store::findAvailableWHLoc(WHLocation** wloc){
    int i = 0;
    for (; i<WHLOCS; i++){
        if (wlocs[i].isAvailable()){
            break;
        }
    }
    *wloc = &wlocs[i];
}

void Store::findProduct(const string& s, Product** p){
    Product* temp;
    products->get(s, &temp);
    *p = &*temp;
}

void Store::printStoreStock(){
    int i = 0;
    for (; i<SLOCS; i++){
        if (slocs[i].isAvailable() == false){
            slocs[i].print();
        }
    }   
}

void Store::printWareHouseStock(){
    int i = 0;
    for (; i<WHLOCS; i++){
        if (wlocs[i].isEmpty() == false){
            wlocs[i].print();
        }
    }   
}

void Store::printProducts(){
    products->print();
}



void Store::receiveProduct(const string& pname, int quantity){
    Product* prod = NULL;
    cout<<"Receiving..."<<endl;
    products->findProduct(pname, &prod);
    if (prod==NULL){
        cout<<"Making new product"<<endl;
        StoreLocation* sloc;
        findAvailableSLoc(&sloc);
        prod = new Product(pname, sloc);
        products->add(prod);   
    }

    WHLocation* bloc;
    while(quantity > 0){
        findAvailableWHLoc(&bloc);
        if (quantity > bloc->getCapacity()){
            bloc->add(pname, bloc->getCapacity());
            prod->addWHLocation(bloc);
            quantity -= bloc->getCapacity();
        }else{
            bloc->add(pname, quantity);
            prod->addWHLocation(bloc);
            quantity = 0;
        }
    }

    cout<<"stocking store location..."<<endl;
    prod->stockStoreLocation();

}

void Store::fillOrder(const string& product, int& quantity){
    Product* prod;
    findProduct(product, &prod);
    if (prod == NULL){
        return;
    }
    prod->fillOrder(quantity);
}


void Store::print(){
    cout<<"Store: "<<name<<endl;
}