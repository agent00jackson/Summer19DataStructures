#include <vector>

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
        double ArrivalTime;
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