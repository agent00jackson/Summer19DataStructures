#include "Lab2.h"
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include <iterator>
#include <algorithm>

#define templ template<class T>

templ DynList<T>::DynList()
{
    this->Length = 50;
    this->dynArr = new T*[Length];
}

templ DynList<T>::~DynList()
{
    delete[] dynArr;
}

templ int DynList<T>::GetLength()
{
    return this->Length;
}

templ void DynList<T>::SetElement(T* obj, int pos)
{
    if(pos < this->Length)
    {
        dynArr[pos] = obj;
    }
}

templ T* DynList<T>::GetElement(int pos)
{
    if(pos >= Length)
    {
        throw "Index out of range!";
    }

    return dynArr[pos];
}

templ void DynList<T>::Push(T* obj)
{
    for(int i = 0; i < Length; i++)
    {
        if(this->dynArr == NULL)
        {
            this->dynArr[i] = obj;
            return;
        }
    }
    this->Expand();
    this->dynArr[Length] = obj;
}

templ void DynList<T>::Expand()
{
    int newLength = Length + 25;
    T** newArr = new T*[newLength];
    std::copy(dynArr, dynArr+Length, newArr);
}

Proc::Proc(std::vector<Proc*>& ProcList)
{
    //Initialize Values
    this->ProcID = (int)this;
    this->PriorityNumber = this->ProcID;
    this->Enlist(ProcList);
    
}

Proc::~Proc()
{
    std::cout << "Proc: " << this->ProcID << " deconstructed!" << std::endl;
}

void Proc::Enlist(std::vector<Proc*>& ProcList)
{
    ProcList.push_back(this);
    std::cout << "Proc: " << this->ProcID << " enlisted." << std::endl;
}

void Proc::Delist(std::vector<Proc*>& ProcList)
{
    std::cout << "Proc " << this->ProcID << " not found." << std::endl;
    return;
}

void Proc::Reset_Priority()
{
    std::cout << "Proc: " << this->ProcID << " priority has been reset." << std::endl;
}

double Proc::Time_In_System()
{
    std::cout << "Proc: " << this->ProcID << " has been in the system for x milliseconds" << std::endl;
    return this->ArrivalTime;
}

double Proc::Waiting_Time()
{
    std::cout << "Proc: " << this->ProcID << " has been waiting for x milliseconds" << std::endl;
    return this->ServiceTime;
}

int main()
{
    std::vector<Proc*> ProcList = std::vector<Proc*>();
    Proc* test = new Proc(ProcList);
    test->Enlist(ProcList);
    test->Delist(ProcList);
    test->Reset_Priority();
    test->Waiting_Time();
    test->Time_In_System();
    return EXIT_SUCCESS;
}