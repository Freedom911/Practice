//Program To Find Height of a given Tree.
//We will do both recursively and non recursively
//For iterative we will simply do level order traversal and return the height
//we can also do inorder traversal but we will have to remember previous hiehg for that
//For recurseively we will simply go deep downthe left and then right and compare which has
//more height and will return that
//https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
#include <iostream>
#include <queue>
#include <stack>
#include <limits>
struct TreeNode
{
  TreeNode*Left;
  TreeNode*Right;
  int data;

  TreeNode(int val)
  {
    Left = Right = nullptr;
    data = val;
  }
};


int getHeightIterative(TreeNode *Node)
{
  int height = 0;

  std::queue<TreeNode*> q;
  q.push(Node);

  while(!q.empty())
  {
    height++;
    
	//explore all children of the nodes present in queue.
	//when all children are visited at a particular level then only increment height
    int size = q.size();
    for(int i = 0; i < size; i++)
    {
      TreeNode*elem = q.front();
      q.pop();

      if(elem->Left)
        q.push(elem->Left);
      if(elem->Right)
        q.push(elem->Right);
    }
  }
  return height;
}

//we use post order with double entry to stack
//we increment height when we insert element in a stack
//we check max height from there
//we decrement height when both the children are visited
int getHeightPostOrderIterative(TreeNode * Root)
{
	if(Root == nullptr)
	{
		return 0;
	}
	int height = 0;
	int maxHeight = std::numeric_limits<int>::min();
	
	std::stack<TreeNode*>st;
	
	while(true)
	{
		while(Root)
		{
			st.push(Root);
			st.push(Root);
			Root = Root->Left;
			height++;
			maxHeight = std::max(maxHeight,height);
		}
		
		if(st.empty())
		{
			return maxHeight;
		}
		
		Root = st.top();
		st.pop();
		
		if(st.size() > 0 && st.top() == Root) // means right child not explored
		{
			Root = Root->Right;
		}
		else
		{
			Root = nullptr;
			height--;
		}
	}
	return maxHeight;
}

//using IBH
//Hypothesis - This  function returns height of tree
int getHeightRecursive(TreeNode*Node)
{
	//Base condition
  if(Node == nullptr)
    return 0;
  
  //Induction step
  int l = getHeightRecursive(Node->Left); //get height of left subtree
  int r = getHeightRecursive(Node->Right);//get height of right subtree
  
  //out of both we pick max
  if(l > r)
    return l + 1; //one is for the root node
  else
    return r + 1;
}

//     1
//  2    3
// 4 5 
//  6 7
//     8
//     9

int main()
{
  TreeNode Root (1);
  TreeNode Node1 (2);
  TreeNode Node2 (3);
  TreeNode Node3 (4);
  TreeNode Node4 (5);
  TreeNode Node5 (6);
  TreeNode Node6 (7);
  TreeNode Node7 (8);
  TreeNode Node8 (9);
  TreeNode Node9 (10);

  Root.Left = &Node1;
  Root.Right = &Node2;
  Node1.Left = &Node3;
  Node1.Right = &Node4;
  Node4.Left = &Node5;
  Node4.Right = &Node6;
  Node6.Right = &Node7;
  Node7.Right = &Node8;
  Node8.Left = &Node9;

  std::cout << "\n Height of tree Recursive == " << getHeightRecursive(&Root);
  std::cout << "\n Height of tree LEvel Order Iterative == " << getHeightIterative(&Root) << "\n";;
  
  std::cout << "\n Height of tree Post Order Iterative == " << getHeightPostOrderIterative(&Root) << "\n";

}






