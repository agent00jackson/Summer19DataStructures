#include "LinkedList.h"
#include <iostream>

#define templ template<typename T>

templ LinkedList<T>::LinkedList()
{
    this->size = 0;
    this->curPos = -1;
    this->curNode = NULL;
    this->head = NULL;
    this->tail = NULL;
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
    else if(curPos == 0)
    {
        return head;
    }
    else if(pos < curPos)
    {
        curNode = head;
        curPos = 0;
        return this->GetAt(pos);
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
    }
    else if(pos == size)
    {
        this->GetAt(pos - 1)->Next = toInsert;
    }
    else
    {
        Node* next = this->GetAt(pos - 1)->Next;
        this->GetAt(pos - 1)->Next = toInsert;
        toInsert->Next = next;
    }
}

templ LinkedList<T>::~LinkedList()
{
    delete head;
}

templ LinkedList<T>::Node::~Node()
{
    if(Next != NULL)
        delete Next;
}