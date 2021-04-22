//Program to check if the tree is bst 
//https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
//We will do inorder traversal and store the result in temp array
//nd then we will check if the array is sorted

#include <iostream>
#include <vector>
#include <stack>

struct TreeNode
{
  TreeNode*LeftChild;
  TreeNode*RightChild;
  int Data;

  TreeNode(int Val)
  {
    LeftChild = RightChild = nullptr;
    Data = Val;
  }
};

//     3
//  2     5
// 1 4
// above is not a bst

std::vector<int> InOrderTraversal(TreeNode*Root)
{
  std::vector<int> v;
  std::stack<TreeNode*>s;
  while(true)
  {
    while(Root != nullptr)
    {
      s.push(Root);
      Root = Root->LeftChild;
    }

    if(s.empty())
      return v;
    Root = s.top();
    s.pop();
    v.push_back(Root->Data);
    Root = Root->RightChild;
  }

  return v;
}

bool IsBst(TreeNode*Root)
{
  std::vector<int> v = InOrderTraversal(Root);
  for(int i = 1; i < v.size(); i++)
  {
    if(v[i-1] > v[i])
      return false;
  }
  return true;
}

int main()
{
#if 0
  TreeNode *Root = new TreeNode(3);
  TreeNode *Node1 = new TreeNode(2);
  TreeNode *Node2 = new TreeNode(5);
  TreeNode *Node3 = new TreeNode(1);
  TreeNode *Node4 = new TreeNode(4);
  Root->LeftChild = Node1;
  Root->RightChild = Node2;
  Node1->LeftChild = Node3;
  Node1->RightChild = Node4;
  std::vector<int> v = InOrderTraversal(Root);
  std::cout << "\n Tree = ";
  for(int i = 0; i < v.size(); i++)
  {
    std::cout << v[i] << " ";
  }
  std::cout << "\n";


  std::cout << "Is the tree BST = " << IsBst(Root);
#else
  TreeNode *Root = new TreeNode(4);
  TreeNode *Node1 = new TreeNode(2);
  TreeNode *Node2 = new TreeNode(5);
  TreeNode *Node3 = new TreeNode(1);
  TreeNode *Node4 = new TreeNode(3);
  Root->LeftChild = Node1;
  Root->RightChild = Node2;
  Node1->LeftChild = Node3;
  Node1->RightChild = Node4;
  std::vector<int> v = InOrderTraversal(Root);
  std::cout << "\n Tree = ";
  for(int i = 0; i < v.size(); i++)
  {
    std::cout << v[i] << " ";
  }

  std::cout << "\n";

  std::cout << "Is the tree BST = " << IsBst(Root);

#endif

}
