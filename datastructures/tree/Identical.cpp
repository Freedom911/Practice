//Check if the two binary trees are identical
//Two trees are identical if they are structurally same
//and their value is same
//we cant just compare two traversals as the final traversal can be same
//for two trees which are not identical
//eg inorder of 1->left->2->left->3->left null
// and inorder of 3->right->2->right->1->right->null
//is 3 2 1
//I show here two ways 1. using recursion and other using level order traversal
#include <iostream>
#include <queue>

struct TreeNode
{
  TreeNode*Left;
  TreeNode*Right;
  int val;

  TreeNode(int val)
  {
    this->val = val;
    Left  = nullptr;
    Right = nullptr;
  }
};

//Hypothesis - This Function Gives true if both trees
//identical false otherwise
bool isSameRec(TreeNode*Root1,TreeNode*Root2)
{
	//Base conditions
	//1. if both are null then that means both have reached their
	//end at same time
	if(Root1 == nullptr && Root2 == nullptr)
	{
		return true;
	}
	
	//2. if either one of them is null then only one met his end so not same
	if(Root1 == nullptr || Root2 == nullptr)
	{
		return false;
	}
	
	//3. If val is not same
	if(Root1->val != Root2->val)
	{
		return false;
	}
	
	//we proceed in other cases
	
	//Induction step
	return isSameRec(Root1->Left,Root2->Left) && isSameRec(Root2->Right,Root2->Right);
}

//using level order traversal
//we verify at each level if the structure is same along with data
//its an iterative approach
bool isSameIterative(TreeNode*Root1,TreeNode*Root2)
{
	//Starting Conditions are same
	//1. if both are null then that means both have reached their
	//end at same time
	if(Root1 == nullptr && Root2 == nullptr)
	{
		return true;
	}
	
	//2. if either one of them is null then only one met his end so not same
	if(Root1 == nullptr || Root2 == nullptr)
	{
		return false;
	}
	
	//3. If val is not same
	if(Root1->val != Root2->val)
	{
		return false;
	}
	std::queue<TreeNode*>q1,q2;
	q1.push(Root1);
	q2.push(Root2);
	
	//Expand both simultaneously
	while(q1.empty() == false && q2.empty() == false)
	{
		TreeNode*n1 = q1.front();
		TreeNode*n2 = q2.front();
		
		//cant be null since we checked initially only and we dont push null ever on queue
		
		//the data is not same
		if(n1->val != n2->val)
		{
			std::cout << "\n Here \n";
			return false;
		}
		
		q1.pop();
		q2.pop();
		
		//1. Check for left condition
		//both tree's left child exists.
		//so structurally same till now
		if(n1->Left && n2->Left)
		{
			q1.push(n1->Left);
			q2.push(n2->Left);
		}
		else if(n1->Left == nullptr && n2->Left == nullptr)
		{
			
		}
		//out of both one is null so structurally not same
		else if(n1->Left == nullptr || n2->Left == nullptr)
		{
			return false;
		}
		
		//same for right child
		//both tree's right child exists.
		//so structurally same till now
		if(n1->Right && n2->Right)
		{
			q1.push(n1->Right);
			q2.push(n2->Right);
		}
		else if(n1->Right == nullptr && n2->Right == nullptr)
		{
			
		}
		//out of both one is null so structurally not same
		else if(n1->Right == nullptr || n2->Right == nullptr)
		{
			return false;
		}
			
	}
	
	//Finally after parsing and checking all nodes
	return true;
}

//   1 
// 2   3
//4 5 6 7

//Level order traversal 
//1 2 3 4 5 6 7
int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->Left = new TreeNode(2);
    root1->Right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->Left = new TreeNode(2);
    root2->Right = new TreeNode(3);
	
	std::cout << "\n Are both trees same rec version = " << isSameRec(root1,root2) << "\n";
	std::cout << "\n Are both trees same iterative version = " << isSameIterative(root1,root2) << "\n";
}
