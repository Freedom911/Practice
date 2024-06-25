//MAX/MIN HEAP
//UNDERLYING CONTAINER - VECTOR,DEQUE
//REQUIREMNET NEED TO be sequential container with random access
//Requeires push_back,pop_back,front



#include <iostream>
#include <queue>
#include <vector>
#include <list>


int main()
{
  //Max Heap
  std::priority_queue<int> pq;
  pq.push(1);
  pq.push(2);
  pq.push(3);
  pq.push(4);
  pq.push(5);

  while(!pq.empty())
  {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  
  std::cout << "\n MIN HEAP \n";

  //min heap
  std::priority_queue<int,std::vector<int>,std::greater<int> > pqmin;
  

  //std::priority_queue<int,std::deque<int>,std::greater<int> > pqmin;
  pqmin.push(1);
  pqmin.push(2);
  pqmin.push(3);
  pqmin.push(4);
  pqmin.push(5);

  while(!pqmin.empty())
  {
    std::cout << pqmin.top() << " ";
    pqmin.pop();
  }


  std::cout << "\n";
 auto cmp = [](std::string l,std::string r) { std::cout << "HERE IT IS = " <<  l << " " << r << "\n"; return l.length() < r.length();};
  std::priority_queue<std::string,std::vector<std::string>,decltype(cmp)> custom(cmp);
  custom.push("ACC");
  custom.push("B");
  //custom.push("CD");
  std::cout << "\n\n";
  while(!custom.empty())
  {
    std::cout << custom.top() << " ";
    custom.pop();
  }
  

}
