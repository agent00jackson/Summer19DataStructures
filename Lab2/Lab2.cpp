#include "Lab2.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <random>

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

void Proc::Enlist(LinkedList<Proc>& ProcList)
{
    ProcList.SetAt(this, ProcList.GetSize());
    std::cout << "Proc: " << this->ProcID << " enlisted." << std::endl;
}

void Proc::Delist(LinkedList<Proc>& ProcList)
{
    ProcList.RemoveItem(this);
    std::cout << "Proc: " << this->ProcID << " delisted." << std::endl;
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

double Proc::Waiting_Time()
{
    std::chrono::duration<double, std::milli> delta = std::chrono::system_clock::now() - (this->ServiceTime);
    std::cout << "Proc: " << this->ProcID << " has been waiting for " << delta.count() << " milliseconds" << std::endl;
    return delta.count();
}

int main()
{
    LinkedList<Proc> ProcList = LinkedList<Proc>(); 
    for(int i = 0; i < 10; i++)
    {
        Proc* test = new Proc();

        test->Enlist(ProcList);

        //test->Reset_Priority();
        //test->Waiting_Time();
        
    }

    for(int i = 0; ProcList.GetSize() > 0; i++)
    {
        Proc* p = ProcList.GetElement(0);
        p->Delist(ProcList);
        p->Time_In_System();
        delete p;
    }
    return EXIT_SUCCESS;
}