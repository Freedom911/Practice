#pragma once
#include "Node.h"
#include <iostream>


template<typename K,typename V>
class DLL
{
    public:
    DLL()
    {
        dummyHead = new Node<K,V>();
        dummyTail = new Node<K,V>();
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    ~DLL()
    {
        if(dummyHead)
        {
            delete dummyHead;
        }

        if(dummyTail)
        {
            delete dummyTail;
        }
    }
    void AddToFront(Node<K,V> *node)
    {
        if(node == nullptr)
        {
            return;
        }

       
        node->next = dummyHead->next;
        node->prev = dummyHead;
        dummyHead->next->prev = node;
        dummyHead->next = node;
        
    }

    void Remove(Node<K,V> *node)
    {
        if(node->prev)
        {
            node->prev->next = node->next;
        }
        
        if(node->next)
        {
            node->next->prev = node->prev;
        }
        
    }

    void MoveToFront(Node<K,V> *node)
    {
        Remove(node);
        AddToFront(node);
    }

    Node<K,V> *RemoveFromLast()
    {
        if(dummyTail->prev == dummyHead)
        {
            return nullptr;
        }
        Node<K,V> *last = dummyTail->prev;
        Remove(last);
        return last;
    }

    void Print()
    {
        std::cout << "\n Printing Cache \n";
        Node<K,V> * node = dummyHead->next;

        while(node && node != dummyTail)
        {
            std::cout << node->key << " : " << node->value << "\n";
            node = node->next;
        }

    }

    

    private:

    Node<K,V> *dummyHead = nullptr;
    Node<K,V> *dummyTail = nullptr;
};