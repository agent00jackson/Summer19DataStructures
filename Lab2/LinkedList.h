#include "ListType.h"
#include "Proc.h"

template<typename T>
class LinkedList : public ListType<T>
{
    public:
        class Node
        {
            public:
                Node* Next;
                T* Data;
                Node(T* Data);
                ~Node();
        };
        Node* GetNodeAt(int);
        Node* GetHead();
        T* GetElement(int);
        int GetSize();
        void SetAt(T*, int);
        LinkedList();
        ~LinkedList();
    private:
        int size;
        int curPos;
        Node* curNode;
        Node* head;
};