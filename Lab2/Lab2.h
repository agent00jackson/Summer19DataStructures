#include <vector>

class Proc
{
    public:
        int ProcID;
        int PriorityNumber;
        double ArrivalTime;
        double ServiceTime;
        void Enlist(std::vector<Proc*>&);
        void Delist(std::vector<Proc*>&);
        void Reset_Priority();
        double Waiting_Time();
        double Time_In_System();
        Proc(std::vector<Proc*>&);
        ~Proc();
    private:
        int QueueSize;
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