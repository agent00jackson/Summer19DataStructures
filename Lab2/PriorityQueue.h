#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#include "DynList.cpp"

template<class T>
class PriorityQueue
{
    public:
        void Push(T*);
        T* Pop(void (*)(T*));
        int GetCurrentSize();
        PriorityQueue();
        ~PriorityQueue();
    private:
        DynList<T>* refArr;
        void BubbleUp(int pos);
};

#include "PriorityQueue_Impl.h"

#endif