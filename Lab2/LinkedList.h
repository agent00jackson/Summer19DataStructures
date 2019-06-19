#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
class LinkedList
{
    public:
        class Node
        {
            public:
                Node* Next;
                T* Data;
                Node(T* Data);
                ~Node();
        };
        Node* GetNodeAt(int);
        Node* GetHead();
        T* GetElement(int);
        int GetSize();
        void SetAt(T*, int);
        void RemoveItem(T*);
        LinkedList();
        ~LinkedList();
    private:
        int size;
        int curPos;
        Node* curNode;
        Node* head;
};

#include "LinkedList_Impl.h"

#endif