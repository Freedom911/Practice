//Program To Print Side View of the tree either left or 
//right https://www.geeksforgeeks.org/print-left-view-binary-tree/
//Logic - Do a level order traversal for left view. Node which is at
//1st position is the left vieww and node which is at last is the right view

#include <iostream>
#include <queue>

template<class T>
struct TreeNode
{
  TreeNode*LeftChild;
  TreeNode*RightChild;
  T Data;

  TreeNode(T Val)
  {
    LeftChild = RightChild = nullptr;
    Data = Val;
  }
};
//          4
//        5   2
//           3 1
//          6 7
//Left View is 4 5 3 6
//Right View is 4 2 1 7
template<class T>
void printView(TreeNode<T>* Root,int leftView)
{
  std::queue<TreeNode<T>*>queue;
  queue.push(Root);

  if(leftView == 0)
  {
    std::cout << "\n Printing Tree in left view \n";

  }
  else
  {
    std::cout << "\n Printing Tree in Right View \n";
  }


  while(!queue.empty())
  {
    int size = queue.size();
    for(int i = 0; i < size;i++)
    {
      TreeNode<T>*Node = queue.front();
      queue.pop();

      if(leftView == 0)
      {
        if(i == 0)
          std::cout << Node->Data << " ";
      }
      else
      {
        if(i == size -1)
          std::cout << Node->Data << " ";
      }

      if(Node->LeftChild != nullptr)
        queue.push(Node->LeftChild);
      if(Node->RightChild != nullptr)
        queue.push(Node->RightChild);
      

    }
  }
}

int main()
{
  TreeNode<int> *Root = new TreeNode<int>(4);
  TreeNode<int> *Node1 = new TreeNode<int>(5);
  TreeNode<int> *Node2 = new TreeNode<int>(2);
  TreeNode<int> *Node3 = new TreeNode<int>(3);
  TreeNode<int> *Node4 = new TreeNode<int>(1);
  TreeNode<int> *Node5 = new TreeNode<int>(6);
  TreeNode<int> *Node6 = new TreeNode<int>(7);
  Root->LeftChild = Node1;
  Root->RightChild = Node2;
  Node2->LeftChild = Node3;
  Node2->RightChild = Node4;
  Node3->LeftChild = Node5;
  Node3->RightChild = Node6;

  int view = 0;
  std::cout << "\n Which view u want 0 - Left ,1 - Right \n";
  std::cin >> view;
  printView(Root,view);

}
