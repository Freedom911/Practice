//Check if the binary tree is foldable
//https://www.geeksforgeeks.org/foldable-binary-trees/
//We will recursively check both the left and right side
//and check if one side gets null first or second side gets
//null second then it is not a foldable tree

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
bool checkIsFoldable(TreeNode<T>*Left,TreeNode<T>*Right)
{
  //Gif both are at same level and both are null then
  //they are foldable so
  if(Left == NULL && Right == NULL)
  {
    return true;
  }

  //if either of them is not null then it is not foldable
  if(Left == NULL || Right == NULL)
  {
    return false;
  }

  return checkIsFoldable(Left->Left,Right->Right) && checkIsFoldable(Left->Right,Right->Left);

}


template<class T>
bool isFoldable(TreeNode<T>*Root)
{
  if(Root == NULL)
    return false;

  return checkIsFoldable(Root->Left,Root->Right);
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
  //Node2->Right = Node6; //on uncommenting this it becomes foldable

  std::cout << "\n IS TREE FOLDABLE  == " << isFoldable(Root) << "\n";
}
