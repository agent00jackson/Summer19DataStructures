#ifndef LAB2_H
#define LAB2_H

#include <chrono>
#include "LinkedList.h"
#include "Queue.h"
#include "Tree.h"

typedef std::chrono::high_resolution_clock::time_point TimeVar;

class Proc
{
    public:
        int ProcID;
        int PriorityNumber;
        TimeVar ArrivalTime;
        TimeVar ServiceTime;
        void Enlist(Tree<Proc>&);
        void Delist(Queue<Proc>&);
        void Reset_Priority();
        double Waiting_Time();
        static double Waiting_Time(Proc*);
        static void PrintWaitingTime(Proc*);
        double Time_In_System();
        Proc();
        ~Proc();
        bool operator<(const Proc&);
        bool operator<=(const Proc&);
        bool operator>(const Proc&);
        bool operator>=(const Proc&);
        bool operator==(const Proc&);
    private:
        int QueueSize;
};

#endif