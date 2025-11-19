#pragma once

template<typename K,typename V>
struct Node
{
    K key;
    V value;
    Node<K,V> *prev;
    Node<K,V> *next;

    Node()
    {
        prev = nullptr;
        next = nullptr;
    }
};

