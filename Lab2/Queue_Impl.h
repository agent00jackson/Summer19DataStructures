#ifndef QUEUE_IMPL_H
#define QUEUE_IMPL_H

#define templ template<class T>

templ Queue<T>::Queue()
{
    queueList = new DynList<T>();
    front = 0;
    currentSize = 0;
}

templ Queue<T>::~Queue()
{
    delete queueList;
}

templ int Queue<T>::GetCapacity()
{
    return queueList->GetLength();
}

templ int Queue<T>::GetCurrentSize()
{
    return currentSize;
}

templ void Queue<T>::Push(T* obj)
{
    if(currentSize == GetCapacity() - 1)
    {
        int newBack = GetCapacity();
        queueList->Expand();
        for(int i = 0; i < front; i++)
        {
            T* toCopy = queueList->GetElement(i);
            queueList->SetElement(toCopy, newBack+i);
        }
    }

    int position = (front + currentSize) % GetCapacity();
    queueList->SetElement(obj, position);
    currentSize++;
}

templ T* Queue<T>::Pop()
{
    T* objToReturn = queueList->GetElement(front);
    front = (front + 1) % GetCapacity();
    currentSize--;
    return objToReturn;
}

#endif