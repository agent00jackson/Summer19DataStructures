#ifndef DYNLIST
#define DYNLIST

template <class T>
class DynList
{
    private:
        T** dynArr;
        int MaxLength;
    public:
        int CurLength;
        void Expand();
        int GetMaxLength();
        T* GetElement(int);
        void SetElement(T*, int);
        void Push(T*);
        DynList();
        ~DynList();
};

#include "DynList_Impl.h"

#endif