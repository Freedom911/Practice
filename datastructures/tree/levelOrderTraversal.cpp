//Level Order Traversal is Level wise parsing
//Starts Parsing From Root
#include <iostream>
#include <queue>

template<class T>
struct TreeNode
{
  TreeNode*Left;
  TreeNode*Right;
  T val;

  TreeNode(T val)
  {
    this->val = val;
    Left  = nullptr;
    Right = nullptr;
  }
};

template<class T>
void LevelOrderTraversal(TreeNode<T>*Root)
{
  std::cout << "\n This is a level order traversal \n";
  std::queue<TreeNode<T>*>queue;
  queue.push(Root);

  while(!queue.empty())
  {
    TreeNode<T>*Node = queue.front();
    queue.pop();
    std::cout << Node->val << " ";
    if(Node->Left)
      queue.push(Node->Left);
    if(Node->Right)
      queue.push(Node->Right);
  }
}

//   1 
// 2   3
//4 5 6 7

//Level order traversal 
//1 2 3 4 5 6 7
int main()
{
  TreeNode<int>*Root = new TreeNode<int>(1);
  TreeNode<int>*Node1 = new TreeNode<int>(2);
  TreeNode<int>*Node2 = new TreeNode<int>(3);
  TreeNode<int>*Node3 = new TreeNode<int>(4);
  TreeNode<int>*Node4 = new TreeNode<int>(5);
  TreeNode<int>*Node5 = new TreeNode<int>(6);
  TreeNode<int>*Node6 = new TreeNode<int>(7);
  Root->Left = Node1;
  Root->Right = Node2;
  Node1->Left = Node3;
  Node1->Right = Node4;
  Node2->Left = Node5;
  Node2->Right = Node6;

  LevelOrderTraversal(Root);
}
