//Code For LRU Implementation. We need o(1) for getting the key and setting the key
//in least recentylu used manner. we will use a mix of hash and linked to achieve this
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

    void refer(int x)
    {
      //check if the cache doesnt contain the key
      if(cache.find(x) == cache.end())
      {

        //check size
        //if equal then remove the last recently used
        if(cache.size() == cacheSize)
        {
          int element = dataList.front();

          //delete from map
          cache.erase(element);
          //remove from starting
          dataList.pop_front();
        }
      }
      //means entry present
      else
      {
        //jsut remove from list
        dataList.erase(cache[x]);
      }

      dataList.push_back(x);
      std::list<int>::iterator i = dataList.end();
      --i;
      cache[x] = i;

    }

    void print()
    {
      for(auto it:dataList)
      {
        std::cout << it << " ";
      }
    }

  private:
    std::unordered_map<int,std::list<int>::iterator> cache;
    std::list<int> dataList;
    int cacheSize;
};

int main()
{
  LRU ca(4);
  ca.refer(1);
  ca.refer(2);
  ca.refer(3);
  ca.refer(1);
  ca.refer(4);
  ca.refer(5);
  ca.print();
}
