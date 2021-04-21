//Inserting a node in binary tree
//We will first find any left node which is null then we find right node
//if left node is full and then try to insert the node there
#include <iostream>
#include <stack>
#include <queue>

template<class T>
struct TreeNode
{
  TreeNode* Left;
  TreeNode* Right;
  T Data;

  TreeNode(T Val)
  {
    Left = NULL;
    Right = NULL;
    Data = Val;
  }

};

//Will Use Queue for it
template<class T>
void InsertNode(TreeNode<T> *root,int value)
{
  std::queue<TreeNode<T>*>queue;

  queue.push(root);

  while(!queue.empty())
  {

    TreeNode<T>*Node = queue.front();
    queue.pop();

    if(Node->Left == NULL)
    {
      Node->Left = new TreeNode<T>(value);
      return;
    }
    else
    {
      queue.push(Node->Left);
    }
    if(Node->Right == NULL)
    {
      Node->Right = new TreeNode<T>(value);
      return;
    }
    else
    {
      queue.push(Node->Right);
    }
  }

}

template<class T>
void InOrderTraversal(TreeNode<T> *root)
{
  std::stack<TreeNode<T>*> stack;

  //Left Root Right
  while(true)
  {
    while(root != NULL)
    {
      stack.push(root);
      root = root->Left;
    }

    if(stack.empty())
      break;
    root = stack.top();
    stack.pop();
    std::cout << root->Data << ",";
    root = root->Right;
  }

}


//      1
//    2   3
//   7   5 6      
//After insertion it gets
//      1
//    2   3
//   7 8 5 6      


int main()
{

  TreeNode<int> *root = new TreeNode<int>(1);
  TreeNode<int> *node1 = new TreeNode<int>(2);
  TreeNode<int> *node2 = new TreeNode<int>(3);
  TreeNode<int> *node3 = new TreeNode<int>(7);
  TreeNode<int> *node4 = new TreeNode<int>(5);
  TreeNode<int> *node5 = new TreeNode<int>(6);
  root->Left = node1;
  root->Right = node2;
  node1->Left = node3;
  node2->Left = node4;
  node2->Right = node5;
  InOrderTraversal(root); //7 2 1 5 3 6

  do
  {
    int value ;
    std::cout << "\n Enter a Value to insert \n";
    std::cin >> value;
   
    InsertNode(root,value);
    InOrderTraversal(root);
  }while(true);


}
