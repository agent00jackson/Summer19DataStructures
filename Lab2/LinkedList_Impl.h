#ifndef LINKEDLIST_IMPL_H
#define LINKEDLIST_IMPL_H

#include "LinkedList.h"
#include <iostream>

#define templ template<typename T>

templ LinkedList<T>::LinkedList()
{
    this->size = 0;
    this->curPos = -1;
    this->curNode = NULL;
    this->head = NULL;
}

#define nodeptr typename LinkedList<T>::Node*

templ T* LinkedList<T>::GetElement(int pos)
{
    return this->GetNodeAt(pos)->Data;
}

templ nodeptr LinkedList<T>::GetNodeAt(int pos)
{
    if(pos >= size)
    {
        throw "Out of bounds!";
    }
    else if(pos == 0)
    {
        return head;
    }
    else if(pos < curPos)
    {
        curNode = head;
        curPos = 0;
        return this->GetNodeAt(pos);
    }
    else if(pos > curPos)
    {
        while(pos > curPos)
        {
            curNode = curNode->Next;
            curPos++;
        }
        return curNode;
    }
}

templ nodeptr LinkedList<T>::GetHead()
{
    return head;
}

templ int LinkedList<T>::GetSize()
{
    return size;
}

templ void LinkedList<T>::SetAt(T* obj, int pos)
{

    Node* toInsert = new Node(obj);
    if(pos == 0)
    {
        toInsert->Next = head;
        this->head = toInsert;
        curPos = 0;
        curNode = head;
    }
    else if(pos == size)
    {
        this->GetNodeAt(pos - 1)->Next = toInsert;
    }
    else
    {
        Node* next = this->GetNodeAt(pos - 1)->Next;
        this->GetNodeAt(pos - 1)->Next = toInsert;
        toInsert->Next = next;
    }
    size++;
}

templ void LinkedList<T>::RemoveItem(T* obj)
{
    Node* lastNode = NULL;
    for(int i = 0; i < this->size; i++)
    {
        Node* n = this->GetNodeAt(i);
        if(n->Data == obj)
        {

            if(i == 0)
            {
                head = n->Next;
                this->size--;
                return;
            }
            else if(i < size-1)
            {
                lastNode->Next = n->Next;
                this->size--;
                return;
            }
            else
            {   
                lastNode->Next == NULL;
                this->size--;
                return;
            }
        }

        lastNode = n;
    }
    std::cout <<"OBJ NOT FOUND\n";
    throw "OBJ NOT FOUND";
}

templ LinkedList<T>::~LinkedList()
{
    delete head;
}

templ LinkedList<T>::Node::Node(T* obj)
{
    this->Next = NULL;
    this->Data = obj;
}

templ LinkedList<T>::Node::~Node()
{
    if(Next != NULL)
        delete Next;
}

#endif