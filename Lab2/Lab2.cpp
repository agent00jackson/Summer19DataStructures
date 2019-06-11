#include "Lab2.h"
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>



proc::proc(std::vector<proc*>& procList)
{
    //Initialize Values
    this->procID = (int)this;
    this->PriorityNumber = this->procID;
    this->Enlist(procList);
}

proc::~proc()
{
    std::cout << "proc: " << this->procID << " deconstructed!" << std::endl;
}

void proc::Enlist(std::vector<proc*>& procList)
{
    procList.push_back(this);
    std::cout << "proc: " << this->procID << " enlisted." << std::endl;
}

void proc::Delist(std::vector<proc*>& procList)
{
    std::cout << "proc " << this->procID << " not found." << std::endl;
    return;
}

void proc::Reset_Priority()
{
    std::cout << "proc: " << this->procID << " priority has been reset." << std::endl;
}

double proc::Time_In_System()
{
    std::cout << "proc: " << this->procID << " has been in the system for x milliseconds" << std::endl;
    return this->ArrivalTime;
}

double proc::Waiting_Time()
{
    std::cout << "proc: " << this->procID << " has been waiting for x milliseconds" << std::endl;
    return this->ServiceTime;
}

int main()
{
    std::vector<proc*> procList = std::vector<proc*>();
    proc* test = new proc(procList);
    test->Enlist(procList);
    test->Delist(procList);
    test->Reset_Priority();
    test->Waiting_Time();
    test->Time_In_System();
    return EXIT_SUCCESS;
}