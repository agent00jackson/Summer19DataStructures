#ifndef PRIORITYQUEUE_IMPL
#define PRIORITYQUEUE_IMPL

#include "DynList.h"
#include "PriorityQueue.h"
#include <iostream>

#define templ template<typename T>

templ PriorityQueue<T>::PriorityQueue()
{
    this->refArr = new DynList<T>();
}

templ PriorityQueue<T>::~PriorityQueue()
{
    delete this->refArr;
}

templ void PriorityQueue<T>::Push(T* obj)
{
    this->refArr->Push(obj);
    this->BubbleUp(refArr->CurLength - 1);
}

templ T* PriorityQueue<T>::Pop(void (*func)(T*)=NULL)
{
    T* popped = this->refArr->GetElement(0);
    T* last = this->refArr->GetElement(refArr->CurLength - 1);
    this->refArr->SetElement(last, 0);
    refArr->CurLength = refArr->CurLength - 1;
    for(int i = 1; i < refArr->CurLength; i++)
    {
        BubbleUp(i);
    }

    if(func != NULL)
    {
        func(popped);
    }

    return popped;
}

templ int PriorityQueue<T>::GetCurrentSize()
{
    return refArr->CurLength;
}

templ void PriorityQueue<T>::BubbleUp(int pos)
{
    if(pos == 0)
    {
        return;
    }
    
    T* focus = this->refArr->GetElement(pos);

    int parentPos = (pos - 1) / 2;
    T* parent = this->refArr->GetElement(parentPos);
    if(*focus > *parent)
    {
        this->refArr->SetElement(parent, pos);
        this->refArr->SetElement(focus, parentPos);
        this->BubbleUp(parentPos);
    }
}

#endif