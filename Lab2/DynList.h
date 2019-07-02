#ifndef DYNLIST
#define DYNLIST

template <class T>
class DynList
{
    private:
        T** dynArr;
        int Length;
    public:
        void Expand();
        int GetLength();
        T* GetElement(int);
        void SetElement(T*, int);
        void Push(T*);
        DynList();
        ~DynList();
};

#endif