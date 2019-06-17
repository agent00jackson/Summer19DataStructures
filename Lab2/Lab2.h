#include <chrono>
typedef std::chrono::high_resolution_clock::time_point TimeVar;

template<class T>
class LinkedList
{
    private:
        class Node
        {
            public:
                Node* Next;
                T* Data
        };
        int size;
        int curPos;
        Node* curNode;
        Node* head;
    public:
        Node* GetAt(int);
        Node* GetHead();
        int GetSize();
        void InsertAt(T*, int);
        LinkedList();
        ~LinkedList();
};

template <class T>
class DynList
{
    private:
        T** dynArr;
        int Length;
        void Expand();
    public:
        int GetLength();
        T* GetElement(int);
        void SetElement(T*, int);
        void Push(T*);
        DynList();
        ~DynList();
};

class Proc
{
    public:
        int ProcID;
        int PriorityNumber;
        TimeVar ArrivalTime;
        double ServiceTime;
        void Enlist(DynList<Proc>&);
        void Delist(DynList<Proc>&);
        void Reset_Priority();
        double Waiting_Time();
        double Time_In_System();
        Proc();
        ~Proc();
    private:
        int QueueSize;
};