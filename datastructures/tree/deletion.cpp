//The Deletion would work like this
//We will replace the content of node to be deleted by the deepest node
//https://www.geeksforgeeks.org/deletion-binary-tree/
#include <iostream>
#include <queue>

template<class T>
struct TreeNode
{
  TreeNode* LeftChild;
  TreeNode* RightChild;
  T Data;

  TreeNode(T Val)
  {
    LeftChild = NULL;
    RightChild = NULL;
    Data = Val;
  }
};

template<class T>
void InorderTraversal(TreeNode<T>*RootNode)
{
  if(RootNode != NULL)
  {
    InorderTraversal(RootNode->LeftChild);
    std::cout << RootNode->Data << ",";
    InorderTraversal(RootNode->RightChild);
  }

}

//queue last will element will be the deepst one
template<typename T>
TreeNode<T>* GetDeepestNode(TreeNode<T>*RootNode)
{

  TreeNode<T>*Node = NULL;
  std::queue<TreeNode<T>*>queue;
  queue.push(RootNode);
  while(!queue.empty())
  {
    Node = queue.front();
    queue.pop();

    if((Node)->LeftChild)
      queue.push((Node)->LeftChild);
    if((Node)->RightChild)
      queue.push((Node)->RightChild);
  }

  return Node;
}

//queue last will element will be the deepst one
template<class T>
TreeNode<T>* GetDesiredNode(TreeNode<T>*RootNode,T val)
{
  std::queue<TreeNode<T>*> queue;
  queue.push(RootNode);
    TreeNode<T>*Node = NULL;

  while(!queue.empty())
  {
    Node = queue.front();
    queue.pop();

    if(Node && Node->Data == val)
      return Node;

    if(Node->LeftChild)
      queue.push(Node->LeftChild);
    if(Node->RightChild)
      queue.push(Node->RightChild);
  }

  return Node;

}

template<class T>
TreeNode<T>* DeleteNode(TreeNode<T>*RootNode,T val)
{
  //step 1 find deepest node

  TreeNode<T>*DeepestNode = GetDeepestNode(RootNode);
  //Step 2 Find Element
// TreeNode<T>*DesiredNode = GetDesiredNode(RootNode,val);
//
// std::swap(DeepestNode->Data,DesiredNode->Data);

  std::cout << "\n Deepest Node is = " << (DeepestNode)->Data << "\n";

  delete DeepestNode;
  DeepestNode = NULL;

  return RootNode;
}



//   10
//  20 30
//       40
//delete 20
//  10
// 40 30

int main()
{
  TreeNode<int>*RootNode = new TreeNode<int>(10);
  TreeNode<int>*Node1 = new TreeNode<int>(20);
  TreeNode<int>*Node2 = new TreeNode<int>(30);
  TreeNode<int>*Node3 = new TreeNode<int>(40);

  RootNode->LeftChild = Node1;
  RootNode->RightChild = Node2;
  Node2->RightChild = Node3;

  InorderTraversal(RootNode); //20 10 30 40
  std::cout << "\n Deleting Node 20 \n";
  RootNode = DeleteNode(RootNode,20);
  InorderTraversal(RootNode); //40 10 30
}
