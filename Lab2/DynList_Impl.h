#ifndef DYNLIST_IMPL
#define DYNLIST_IMPL

#include "DynList.h"
#include <iostream>

#define templ template<class T>

templ DynList<T>::DynList()
{
    this->CurLength = 0;
    this->MaxLength = 50;
    this->dynArr = new T*[MaxLength];
    for(int i = 0; i < MaxLength; i++)
    {
        this->dynArr[i] = NULL;
    }
}

templ DynList<T>::~DynList()
{
    delete[] dynArr;
}

templ int DynList<T>::GetMaxLength()
{
    return this->MaxLength;
}

templ void DynList<T>::SetElement(T* obj, int pos)
{
    if(pos < this->MaxLength)
    {
        dynArr[pos] = obj;
    }
}

templ T* DynList<T>::GetElement(int pos)
{
    if(pos >= MaxLength)
    {
        throw "Index out of range!";
    }

    return dynArr[pos];
}

templ void DynList<T>::Push(T* obj)
{
    if(CurLength >= MaxLength)
    {
        this->Expand();
    }
    this->dynArr[CurLength] = obj;
    CurLength++;
}

templ void DynList<T>::Expand()
{
    int newMaxLength = MaxLength + 25;
    T** newArr = new T*[newMaxLength];
    std::copy(dynArr, dynArr+MaxLength, newArr);
    delete[] dynArr;
    dynArr = newArr;
    for(int i = MaxLength; i < newMaxLength; i++)
    {
        this->dynArr[i] = NULL;
    }
    MaxLength = newMaxLength;
}

#endif