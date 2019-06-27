#ifndef TREE_H
#define TREE_H

#include "Queue.h"

template<class T>
class Tree
{
    public:
        class Node
        {
            public:
                Node* Left;
                Node* Right;
                T* Data;
                bool IsLeaf();
                void NTraverse(void (*)(T*));
                void NAdd(T*, Queue<Node>*);
                Node(T*);
                ~Node();
        };
        void Traverse(void (*)(T*));
        void Add(T*);
        void Clear();
        Tree();
        ~Tree();
    private:
        Queue<Node>* refQ;
        Node* rootNode;
};

#include "Tree_Impl.h"

#endif