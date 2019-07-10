#include "Lab2.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <random>
#include <limits>

#pragma region PROC

Proc::Proc()
{
    std::random_device rd; 
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0,1000); 

    //Initialize Values
    this->ProcID = uni(rng);
    this->PriorityNumber = uni(rng);
    this->ArrivalTime = std::chrono::system_clock::now();
    this->ServiceTime = this->ArrivalTime;
}

Proc::~Proc()
{
    std::cout << "Proc: " << this->ProcID << " deconstructed!" << std::endl;
}

void Proc::Enlist(PriorityQueue<Proc>& ProcList)
{
    ProcList.Push(this);
    std::cout << "Proc: " << this->ProcID << " enlisted." << std::endl;
}

void Proc::Delist(Queue<Proc>& ProcList)
{
    //ProcList.Pop(this);
    //std::cout << "Proc: " << this->ProcID << " delisted." << std::endl;
    return;
}

void Proc::Reset_Priority()
{
    this->PriorityNumber = 0;
    std::cout << "Proc: " << this->ProcID << " priority has been reset." << std::endl;
}

double Proc::Time_In_System()
{
    std::chrono::duration<double, std::milli> delta = std::chrono::system_clock::now() - (this->ArrivalTime);
    std::cout << "Proc: " << this->ProcID << " has been in the system for " << delta.count() << "ms" << std::endl;
    return delta.count();
}

double Proc::Waiting_Time(Proc* proc)
{
    std::chrono::duration<double, std::milli> delta = std::chrono::system_clock::now() - (proc->ServiceTime);
    return delta.count();
}

double Proc::Waiting_Time()
{
    return Proc::Waiting_Time(this);
}

void Proc::PrintWaitingTime(Proc* proc)
{
    std::cout << "Proc: " << proc->ProcID << " has been waiting for " << proc->Waiting_Time() << " milliseconds" << std::endl;
}

bool Proc::operator<(const Proc& other)
{
    return (this->PriorityNumber < other.PriorityNumber);
}

bool Proc::operator==(const Proc& other)
{
    return (this->PriorityNumber == other.PriorityNumber);
}

bool Proc::operator>(const Proc& other)
{
    return (this->PriorityNumber > other.PriorityNumber);
}

bool Proc::operator<=(const Proc& other)
{
    return (this->PriorityNumber < other.PriorityNumber) || (this->PriorityNumber == other.PriorityNumber);
}

bool Proc::operator>=(const Proc& other)
{
     return (this->PriorityNumber > other.PriorityNumber) || (this->PriorityNumber == other.PriorityNumber);
}

#pragma endregion PROC

double* Scheduler(Queue<Proc>& ProcList)
{
    double* stats = new double[3];
    double minWait = std::numeric_limits<double>::max();
    double maxWait = 0;
    double totalWait = 0;
    int count = 0;
    while(ProcList.GetCurrentSize() > 0)
    {
        Proc* popped = ProcList.Pop(Proc::PrintWaitingTime);
        std::cout << "Priority: " << popped->PriorityNumber << std::endl;
        double waitTime = popped->Waiting_Time();
        totalWait += waitTime;
        if(waitTime > maxWait) maxWait = waitTime;
        if(waitTime < minWait) minWait = waitTime;
        count++;
        delete popped;
    }

    stats[0] = minWait;
    stats[1] = maxWait;
    stats[2] = totalWait/count;

    return stats;
}

int main()
{
    PriorityQueue<Proc> ProcList = PriorityQueue<Proc>(); 
    for(int i = 0; i < 10; i++)
    {
        Proc* test = new Proc();
        test->Enlist(ProcList);
    }

    Queue<Proc> finalq = Queue<Proc>();
    while(ProcList.GetCurrentSize() > 0)
    {
        finalq.Push(ProcList.Pop());
    }

    double* stats = Scheduler(finalq);
    std::cout << "Average waiting time: " << stats[2] << "ms\n";
    std::cout << "Min waiting time: " << stats[0] << "ms\n";
    std::cout << "Max waiting time: " << stats[1] << "ms\n";
    
    return EXIT_SUCCESS;
}