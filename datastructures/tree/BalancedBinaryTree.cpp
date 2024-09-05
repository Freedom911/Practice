/**
 Given a Binary Tree we need to find if the tree is balanced or not
 A balanced binary tree is a tree in which the diff between height of left subtree
 and height of right subtree is at most 1
 We use our previous knowledge that is our power of get height to find the solution
 */

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

//Hypothesis This Functions checks that the tree is valid or not
int CheckIsBalanced(TreeNode*Root)
{
   if(Root == nullptr)
   {
	   return 0;
   }
   
   int l = CheckIsBalanced(Root->Left);
   
   if(l == -1)
	   return -1;
   
   int r = CheckIsBalanced(Root->Right);
   
   if(r == -1)
	   return -1;
   
   if(std::abs(l - r) > 1)
   {
	   return -1;
   }
   
   return std::max(l,r) + 1;

   
}




int main()
{

   TreeNode* root = new TreeNode(10);
    root->Left = new TreeNode(5);
    root->Right = new TreeNode(30);
    root->Right->Left = new TreeNode(15);
    root->Right->Right = new TreeNode(20);
	root->Right->Right->Right = new TreeNode(30);
  
  std::cout << "\n Is Tree Balanced = " << (CheckIsBalanced(root) > 0) << "\n";
  
}

