//Given a preorder traversal check if the tree is a binary search tree
//https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
//Prerequiste To Find Next Greater Array. Logic Defined in my notebook in one drive
#include <iostream>
#include <vector>
#include <stack>
#include <limits>

bool checkIsBST(std::vector<int> ar)
{
  std::stack<int> s;
  s.push(ar[0]);
  int root = std::numeric_limits<int>::min();

  for(int i = 1; i < ar.size(); i++)
  {
    if(ar[i] < root)
      return false;


    while(s.empty() == false && s.top() <  ar[i])
    {
      root = s.top();
      s.pop();
    }

    s.push(ar[i]);
  }

  return true;

}

std::ostream &operator <<(std::ostream &os,const std::vector<int> &elem)
{
  for(auto &e:elem)
  {
    os << e << " ";
  }

  return os;
}

int main()
{
  std::vector<int> ar{2,4,1};
  std::vector<int> ar1{2,4,3};
  std::vector<int> ar2{40, 30, 35, 80, 100};
  std::vector<int> ar3{40, 30, 35, 20, 80, 100};

  std::cout << "\n IS BST = " << ar << " " << checkIsBST(ar) << "\n";
  std::cout << "\n IS BST = " << ar1 << " " << checkIsBST(ar1) << "\n";
  std::cout << "\n IS BST = " << ar2 << " " << checkIsBST(ar2) << "\n";
  std::cout << "\n IS BST = " << ar3 << " " << checkIsBST(ar3) << "\n";

}
