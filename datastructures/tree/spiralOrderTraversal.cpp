//Spiral Order Traversal is Level wise parsing
//Starts Parsing From Root
//https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/
// for Tree
//                  1
//              2       3
//           4    5   6   7
//Spiral Order would be 1,2,3,7,6,5,4
#include <iostream>
#include <queue>
#include <stack>

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


//Using Stack to print reslt in reverse
template<class T>
void SpiralLevelOrderTraversal(TreeNode<T>*Root)
{
  std::cout << "\n This is a spiral level order traversal \n";
  std::queue<TreeNode<T>*>queue;
  queue.push(Root);

  int i = 0;
  while(!queue.empty())
  {
    int n = queue.size();
    std::stack<T> st;
    for(int j = 0;j < n; j++)
    {
      TreeNode<T>*Node = queue.front();
      queue.pop();

      if(i % 2 != 0)
      {
        std::cout << Node->val << " ";
      }
      else
        st.push(Node->val);
      if(Node->Left)
        queue.push(Node->Left);
      if(Node->Right)
        queue.push(Node->Right);
    }
    i++;
    while(!st.empty())
    {
      T v = st.top();
      st.pop();
      std::cout << v << " ";
    }
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


  TreeNode<int>*Node7 = new TreeNode<int>(8);
  TreeNode<int>*Node8 = new TreeNode<int>(9);
  TreeNode<int>*Node9 = new TreeNode<int>(10);
  TreeNode<int>*Node10 = new TreeNode<int>(11);
  TreeNode<int>*Node11 = new TreeNode<int>(12);
  TreeNode<int>*Node12 = new TreeNode<int>(13);
  TreeNode<int>*Node13 = new TreeNode<int>(14);
  TreeNode<int>*Node14 = new TreeNode<int>(15);

  Root->Left = Node1;
  Root->Right = Node2;
  Node1->Left = Node3;
  Node1->Right = Node4;
  Node2->Left = Node5;
  Node2->Right = Node6;
  Node3->Left = Node7;
  Node3->Right = Node8;
  Node4->Left = Node9;
  Node4->Right = Node10;
  Node5->Left = Node11;
  Node5->Right = Node12;
  Node6->Left = Node13;
  Node6->Right = Node14;


  SpiralLevelOrderTraversal(Root);
}
