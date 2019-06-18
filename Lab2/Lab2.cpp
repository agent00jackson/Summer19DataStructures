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

void Proc::Enlist(LinkedList<Proc>& ProcList)
{

}

void Proc::Delist(LinkedList<Proc>& ProcList)
{
    LinkedList<Proc>::Node* prevNode = NULL;
    for(int i = 0; i < ProcList.GetSize(); i++)
    {
        LinkedList<Proc>::Node* curNode = ProcList.GetNodeAt(i);
        if(curNode->Data == this)
        {
            
            prevNode->Next = curNode->Next;
            std::cout << "Proc " << this->ProcID << " found in position " << i << " and deleted\n";
            return;
        }
    }
    std::cout << "Proc " << this->ProcID << " not found.\n";
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
    Proc* test = new Proc();
    test->Enlist(ProcList);
    test->Delist(ProcList);
    test->Reset_Priority();
    test->Waiting_Time();
    test->Time_In_System();
    delete test;
    return EXIT_SUCCESS;
}