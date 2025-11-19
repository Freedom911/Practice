#pragma once
#include <unordered_map>
#include "DLL.h"
#include "Node.h"
#include <iostream>

template<typename K,typename V>
class LRUCache
{
    public:
    LRUCache(int capacity)
    {
        m_capacity = capacity;
        m_cacheList = new DLL<K,V>();
    }

    ~LRUCache()
    {
        for(auto iter: m_cacheMap)
        {
            delete iter.second;
        }

        delete m_cacheList;
    }

    V Get(K key)
    {
        //std::lock_guard<std::mutex> lock(m_mutex);
        if(m_cacheMap.find(key) == m_cacheMap.end())
        {
            std::cout << "\n Element Not Found = \n";
            return V{};
        }
        else
        {
            Node<K,V> *node = m_cacheMap[key];
            m_cacheList->MoveToFront(node);
            return node->value;
        }
    }

    void Put(K key,V value)
    {

        //1. First Check if element already present then we change the value and mvoe to front
        //2. If not we check the cache is full ornot .if full we remove the last and at last we
        //3. Insert the new node to DLL and map
        //std::lock_guard<std::mutex> lock(m_mutex);
        if(m_cacheMap.find(key) != m_cacheMap.end())
        {
            Node<K,V> *node = m_cacheMap[key];
            node->value = value;
            //Update in Map
            m_cacheMap[key] = node;
            //Update in DLL
            m_cacheList->MoveToFront(node);
        }
        else
        {
            //check cache size
            if(m_cacheMap.size() == m_capacity)
            {
                //Remove the last  from DLL First
                Node<K,V> *node = m_cacheList->RemoveFromLast();

                //from Map Now
                if(node)
                {
                    m_cacheMap.erase(node->key);

                    //free up the memory
                    delete node;
                }
                
            }
            
            Node<K,V> *node = new Node<K,V>();
            node->key = key;
            node->value = value;

            //INsert node in dll
            m_cacheList->AddToFront(node);
            m_cacheMap[key] = node;
        }
    }

    void Print()
    {
        m_cacheList->Print();         
    }

    private:
    int m_capacity;
    DLL<K,V> *m_cacheList;
    std::unordered_map<K,Node<K,V>*> m_cacheMap;
};