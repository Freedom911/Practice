//Finding LCA in a binary search tree. It's a binary search tree and not a binary tree
// Exaple
//                   20
//                8     22
//              4  12
//                10 14
//LCA of 4 and 14 is 8 
//LCA of 10 and 14 is 12
//LCA of 22 and 10 is 20
// https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
//We will follow the approach her if both the values are less than a node then 
//Move left else move right
//Other wise if any condition is not fullfilled then reutnr the node
//assuming Nodes are there

#include <iostream>
#include <queue>
#include <stack>

struct TreeNode
{
  TreeNode*Left;
  TreeNode*Right;
  int Data;

  TreeNode(int val)
  {
    this->Data = val;
    Left  = nullptr;
    Right = nullptr;
  }
};

int findLCA(TreeNode*Root,int a,int b)
{
  while(Root != NULL)
  {
    if(Root->Data > a && Root->Data > b)
      Root = Root->Left;
    else if(Root->Data < a && Root->Data < b)
      Root = Root->Right;
    else
      break;
  }

  if(Root)
  return Root->Data;
  else
  {
    std::cout << "\n Cannot Find LCA \n";
    return -1;
  }
}




int main()
{
  TreeNode*Root = new TreeNode(20);
  TreeNode*Node1 = new TreeNode(8);
  TreeNode*Node2 = new TreeNode(22);

  TreeNode*Node3 = new TreeNode(4);
  TreeNode*Node4 = new TreeNode(12);
  TreeNode*Node5 = new TreeNode(10);
  TreeNode*Node6 = new TreeNode(14);
  Root->Left = Node1;
  Root->Right = Node2;
  Node1->Left = Node3;
  Node1->Right = Node4;
  Node4->Left = Node5;
  Node4->Right = Node6;



  std::cout << "\n LCA for(4,14) is ==== " << findLCA(Root,4,14); //8
  std::cout << "\n LCA for(10,22) is ==== " << findLCA(Root,10,22);//20
}
