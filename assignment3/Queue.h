#ifndef QUEUE_H
#define QUEUE_H

#include "WHLocation.h" 

class Queue {

    class Node {
        public:
            WHLocation* data;
            Node*    next;
    };

    public:
        Queue();
        ~Queue();

        bool isEmpty() const;
        void peekFirst(WHLocation**);
        void popFirst(WHLocation**);
        void addLast(WHLocation*);
        void print() const;

    private:
        Node* head;
        Node* tail;
};

#endif