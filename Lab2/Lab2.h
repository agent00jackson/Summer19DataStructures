#ifndef LAB2_H
#define LAB2_H

#include <chrono>
#include "LinkedList.h"
#include "Queue.h"

typedef std::chrono::high_resolution_clock::time_point TimeVar;

class Proc
{
    public:
        int ProcID;
        int PriorityNumber;
        TimeVar ArrivalTime;
        TimeVar ServiceTime;
        void Enlist(LinkedList<Proc>&);
        void Delist(LinkedList<Proc>&);
        void Reset_Priority();
        double Waiting_Time();
        double Time_In_System();
        Proc();
        ~Proc();
    private:
        int QueueSize;
};

#endif