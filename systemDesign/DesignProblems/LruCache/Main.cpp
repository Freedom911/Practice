#include "LRUCache.h"
#include <iostream>
#include <string>

int main()
{
    LRUCache<std::string,int> * cache = new LRUCache<std::string,int>(3);

    cache->Put("a",1);
    cache->Put("b",2);
    cache->Put("c",3);
    cache->Print();
    std::cout << "Getting A = " << cache->Get("a") << std::endl; // 1
    cache->Print();

     // Adding 'd' will cause 'b' (the current LRU item) to be evicted
    cache->Put("d", 4);
    cache->Print();
        
        // Trying to get 'b' should now return null
    std::cout << "Getting B = " << cache->Get("b") << std::endl; // 
    cache->Print();

}