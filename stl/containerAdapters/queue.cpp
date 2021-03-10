//QUEUE
//UNDERLYING CONTAINER - DEQUEUE,LIST
//REQUIREMENT only requiresequential container
//Needs back,front push_back pop front


#include <iostream>
#include <queue>
#include <list>

int main()
{
  //Max Heap
  std::queue<int,std::deque<int>> pq;
// std::queue<int,std::list<int>> pq;
// std::queue<int> pq;
//  std::queue<int,std::deque<float>> pq; undefined since c++17
  pq.push(1);
  pq.push(2);
  pq.push(3);
  pq.push(4);
  pq.push(5);

  while(!pq.empty())
  {
    std::cout << pq.front() << " ";
    pq.pop();
  }
  


}
