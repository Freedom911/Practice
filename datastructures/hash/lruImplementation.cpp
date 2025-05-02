//Code For LRU Implementation. We need o(1) for getting the key and setting the key
//in least recentylu used manner. we will use a mix of hash and linked to achieve this
//So Basically What we needis O(1)
//if we have used just a simple queue then pushing will be O(1) but getting Value will take
//O(n)
//Similarly we cant simply use hashing as we require in order 
//So we use Hybrid Solution of Using hashing and Linked List
//https://www.geeksforgeeks.org/lru-cache-implementation/

#include <iostream>
#include <unordered_map>
#include <list>

class LRU
{

  public:

    LRU(int size)
    {
      cacheSize =  size;
    }

    //This Gets The Key if present 
    //it will also push at last
    int get(int key)
    {
        //Element is not present
        if(cache.find(key) == cache.end())
        {
            return -1;
        }
        else
        {
            std::list<std::pair<int,int>>::iterator iter = cache[key];
            int value = (*iter).second;
            dataList.erase(cache[key]);
            dataList.push_back({key,value});
            std::list<std::pair<int,int>>::iterator i = dataList.end();
            --i;
            cache[key] = i;
            return value;
        }
    }

    //Inserts into Cache
    void put(int key,int value)
    {
      //check if the cache doesnt contain the key
      if(cache.find(key) == cache.end())
      {

        //check size
        //if equal then remove the last recently used
        if(cache.size() == cacheSize)
        {
          int key = dataList.front().first;

          //delete from map
          cache.erase(key);
          //remove from starting
          dataList.pop_front();
        }
      }
      //means entry present
      else
      {
        //jsut remove from list
        //Erase while giving a node iterator is O(1) 
        dataList.erase(cache[key]);
      }

      dataList.push_back({key,value});
      std::list<std::pair<int,int>>::iterator i = dataList.end();
      --i;
      cache[key] = i;

    }

    void print()
    {
      for(auto it:dataList)
      {
        std::cout << it.first << " " << it.second << "\n";
      }
    }

  private:
    std::unordered_map<int,std::list<std::pair<int,int>>::iterator> cache;
                        //key->value
    std::list<std::pair<int,int>> dataList;
    int cacheSize;
};

int main()
{
  LRU ca(4);
  ca.put(1,1);
  ca.put(2,2);
  ca.put(3,4);
  ca.put(1,6);
  ca.put(4,7);
  ca.put(5,8);
  ca.print();
}
