#ifndef QUEUE_H
#define QUEUE_H

#include "DynList.cpp"

template<class T>
class Queue
{
    public:
        Queue();
        ~Queue();
        void Push(T*);
        T* Pop();
        T* Peek();
        int GetCapacity();
        int GetCurrentSize();
    private:
        DynList<T>* queueList;
        int front;
        int currentSize;
};

#include "Queue_Impl.h"
#endif