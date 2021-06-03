//Print all the subsets of a set
#include <iostream>
#include <string>
#include <unordered_set>

void print(std::string ip,std::string op)
{
  //Base Condition
  if(ip.size() == 0)
  {
    std::cout << "\n SUBSET = " << op << "\n";
    return;
  }

  std::string op1 = op;
  std::string op2 = op;


  op2.push_back(ip[0]);

  //reduce ip
  ip.erase(ip.begin() + 0);

  //left substree
  print(ip,op1);

  //right subtree
  print(ip,op2);

}

void print(std::string ip,std::string op,std::unordered_set<std::string> &set)
{
  //Base Condition
  if(ip.size() == 0)
  {
    if(set.find(op) == set.end())
    std::cout << "\n SUBSET = " << op << "\n";
    set.insert(op);
    return;
  }

  std::string op1 = op;
  std::string op2 = op;



  op2.push_back(ip[0]);


  //reduce ip
  ip.erase(ip.begin() + 0);

  //left substree
  print(ip,op1,set);

  //right subtree
  print(ip,op2,set);

}

int main()
{
  //print("ab","");
  std::cout << "\n UNIQUE = \n";
  std::unordered_set<std::string> set;
  print("abc","",set);
}
