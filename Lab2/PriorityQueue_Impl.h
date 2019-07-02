#ifndef PRIORITYQUEUE_IMPL
#define PRIORITYQUEUE_IMPL

#include "DynList.cpp"
#include "PriorityQueue.h"

#define templ template<typename T>

templ PriorityQueue::PriorityQueue()
{
    this->refArr = new DynList();
}

templ PriorityQueue::~PriorityQueue()
{
    delete this->refArr;
}

templ void PriorityQueue::Push(T* obj)
{
    this->refArr->Push(obj);
    this->BubbleUp(refArr->Length - 1);
}

templ T* PriorityQueue::Pop(void (*func)(T*)=NULL)
{
    T* popped = this->refArr->GetElement(0);
    T* last = this->refArr->GetElement(refArr->Length - 1);
    this->refArr->SetElement(last, 0);
    refArr->Length = refArr->Length - 1;
    for(int i = 1; i < refArr->Length; i++)
    {
        BubbleUp(i);
    }
}

templ int PriorityQueue::GetCurrentSize()
{
    return refArr->Length;
}

templ void PriorityQueue::BubbleUp(int pos)
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
        this->refAtt->SetElement(focus, parentPos);
        this->BubbleUp(parentPos);
    }
}

#endif