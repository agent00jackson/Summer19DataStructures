#include "DynList.h"
#include <iostream>

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