template<class T>
class LinkedList
{
    private:
        class Node
        {
            public:
                Node* Next;
                T* Data;
        };
        int size;
        int curPos;
        Node* curNode;
        Node* head;
    public:
        Node* GetAt(int);
        Node* GetHead();
        int GetSize();
        void InsertAt(T*, int);
        LinkedList();
        ~LinkedList();
};