#include "Lab2.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>

#define templ template<class T>

templ DynList<T>::DynList()
{
    this->Length = 50;
    this->dynArr = new T*[Length];
    for(int i = 0; i < Length; i++)
    {
        this->dynArr[i] = NULL;
    }
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
        if(this->dynArr[i] == NULL)
        {
            this->dynArr[i] = obj;
            std::cout << "Object inserted at " << i << '\n';
            return;
        }
    }
    std::cout << "Array full, expanding\n";
    this->Expand();
    this->dynArr[Length] = obj;
}

templ void DynList<T>::Expand()
{
    int newLength = Length + 25;
    T** newArr = new T*[newLength];
    std::copy(dynArr, dynArr+Length, newArr);
    delete[] dynArr;
    dynArr = newArr;
    for(int i = Length; i < newLength; i++)
    {
        this->dynArr[i] = NULL;
    }
    Length = newLength;
}

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

void Proc::Enlist(DynList<Proc>& ProcList)
{
    ProcList.Push(this);
    std::cout << "Proc: " << this->ProcID << " enlisted." << std::endl;
}

void Proc::Delist(DynList<Proc>& ProcList)
{
    for(int i = 0; i < ProcList.GetLength(); i++)
    {
        if(ProcList.GetElement(i) == this)
        {
            ProcList.SetElement(NULL, i);
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
    DynList<Proc> ProcList = DynList<Proc>();
    Proc* test = new Proc();
    test->Enlist(ProcList);
    test->Delist(ProcList);
    test->Reset_Priority();
    test->Waiting_Time();
    test->Time_In_System();
    delete test;
    return EXIT_SUCCESS;
}