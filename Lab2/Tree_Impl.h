#ifndef TREE_IMPL_H
#define TREE_IMPL_H

#include "Tree.h"
#include "Queue.h"
#define templ template<typename T>

templ Tree<T>::Node::Node(T* data)
{
    Data = data;
    Left = NULL;
    Right = NULL;
}

templ void Tree<T>::Node::NAdd(T* data, Queue<Node>* refQ)
{
    Node* insNode = new Node(data);
    if(insNode->Left != NULL)
    {
        Left = insNode;
        refQ->Push(insNode);
    }
    else
    {
        Right = insNode;
        refQ->Pop();
        refQ->Push(insNode);
    }
}

templ bool Tree<T>::Node::IsLeaf()
{
    return (Left == NULL) && (Right == NULL);
}

templ Tree<T>::Node::~Node()
{
    if(Left != NULL) delete this->Left;
    if(Right != NULL) delete this->Right;
}

templ void Tree<T>::Node::NTraverse(void (*func)(T*))
{
    if(Left != NULL)
    {
        Left->NTraverse(func);
    }

    func(Data);

    if(Right != NULL)
    {
        Right->NTraverse(func);
    }
}

templ void Tree<T>::Traverse(void (*func)(T*))
{
    rootNode->NTraverse(func);
}

templ void Tree<T>::Add(T* data)
{
    if(refQ->GetCurrentSize() == 0)
    {
        Node* newNode = new Node(data);
        rootNode = newNode;
        refQ->Push(newNode);
    }
    else
    {
        Node* peekNode = refQ->Peek();
        peekNode->NAdd(data, refQ);
    }
}

templ Tree<T>::Tree()
{
    rootNode == NULL;
    refQ = new Queue<Node>();
}

templ Tree<T>::~Tree()
{
    delete rootNode;
    delete refQ;
}

#endif