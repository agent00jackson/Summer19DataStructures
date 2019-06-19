#include "Lab2.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>

Proc::Proc()
{
    //Initialize Values
    this->ProcID = (int)this;
    this->PriorityNumber = this->ProcID;
    this->ArrivalTime = std::chrono::system_clock::now();
    
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
    std::cout << "Proc: " << this->ProcID << " has been waiting for x milliseconds" << std::endl;
    return this->ServiceTime;
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