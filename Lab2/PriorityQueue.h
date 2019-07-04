#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#include "DynList.h"

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
        void BubbleDown(int pos);
};

#include "PriorityQueue_Impl.h"

#endif