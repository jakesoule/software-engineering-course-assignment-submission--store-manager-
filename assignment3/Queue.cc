#include <iostream>
#include <string>

#include "Queue.h"

using namespace std;

Queue::Queue(): head(NULL), tail(NULL){}

Queue::~Queue(){
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode != NULL){
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}

bool Queue::isEmpty() const{
    if (head == NULL){
        return true;
    }
    return false;
}

void Queue::peekFirst(WHLocation** loc){
    if (head == NULL){
        *loc = NULL;
        return;
    }

    *loc = head->data;
}

void Queue::popFirst(WHLocation** loc){
    Node* currNode = head;

    if (currNode == NULL){
        *loc = NULL;
        tail = NULL;
        return;
    }

    if (currNode->next == NULL){
        *loc = currNode->data;
        head = NULL;
        tail = NULL;
        return;
    }

    *loc = currNode->data;
    head = currNode->next;
}

void Queue::addLast(WHLocation* loc){
    Node* newNode = new Node();
    newNode->data = loc;
    newNode->next = NULL;

    Node* currNode = tail;

    if (head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    currNode->next = newNode;
    tail = currNode->next;
}



void Queue::print() const{
    Node* currNode = head;

    while(currNode != NULL){
        currNode->data->print();
        currNode = currNode->next;
    }
}