/**
 Given a Binary Tree we need to find the maximum Sum between any two leaf nodes
 The prior knowledge we are using is of Tree Diameter please check that
 https://github.com/Freedom911/Practice/blob/master/algorithms/dynamic/TreeDiameter.cpp
 */
 

#include <iostream>
#include <unordered_map>
#include <limits>

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

//Hypothesis - This function returns the max sum between any two leaf nodes
int findMaxSum(TreeNode*Root,int &maxAns)
{
	//Base condition
	if(Root == nullptr)
	{
		return 0;
	}
	
	//Induction Step
	int l = findMaxSum(Root->Left,maxAns);
	int r = findMaxSum(Root->Right,maxAns);
	
	//Let us maginfy what is happening
	//Root->data only means we will use only root value 
	//max(l,r) + Root->data means l,r m se maximum jo ho usko add karo root->data maginfy
	//root->data kab bada hoga when it values are negative and addiing
	//them make it worse. We shall pass this result for further analysos
	int MainRootInvolved = std::max(Root->Data,std::max(l,r) + Root->Data);
	
	//Other thing is we dont want to include the top most root. Root is one only
	//so we use subtree only and dont invlove root main 
	//here root ->data is basically the root of subtree
	int MainRootNotInvolved = l + r + Root->Data;
	
	int ans = std::max(MainRootInvolved,MainRootNotInvolved);//pick max of these
	
	maxAns = std::max(maxAns,ans);
	
	//we pass the result for further analysis.
	//we dont pass where Main Root is not involved
	//with hope that we might get better ans than maxAns
	return MainRootInvolved;
	
	
	
}

//we use DP here to store result 
int findMaxSumDP(TreeNode*Root,int &maxAns,std::unordered_map<TreeNode*,int> &us)
{
	//Base condition
	if(Root == nullptr)
	{
		return 0;
	}
	
	//Induction Step
	int l = -1;
	int r = -1;
	
	//using dp to check if result already evaluated
	if(us.find(Root->Left) != us.end())
	{
		l = us[Root->Left];
	}
	else
	{
		std::cout << "\n Already Evaluated \n";
		us[Root->Left] = l = findMaxSumDP(Root->Left,maxAns,us);
	}
	
	//using dp to check if result already evaluated
	if(us.find(Root->Right) != us.end())
	{
		std::cout << "\n Already Evaluated \n";
		r = us[Root->Right];
	}
	else
	{
		us[Root->Right] = r = findMaxSumDP(Root->Right,maxAns,us);
	}
	

	
	
	int MainRootInvolved = std::max(Root->Data,std::max(l,r) + Root->Data);
	
	//Other thing is we dont want to include the top most root. Root is one only
	//so we use subtree only and dont invlove root main 
	//here root ->data is basically the root of subtree
	int MainRootNotInvolved = l + r + Root->Data;
	
	int ans = std::max(MainRootInvolved,MainRootNotInvolved);//pick max of these
	
	maxAns = std::max(maxAns,ans);
	
	//we pass the result for further analysis.
	//we dont pass where Main Root is not involved
	//with hope that we might get better ans than maxAns
	return MainRootInvolved;
	
	
	
}

// Driver code
int main(void)
{
    struct TreeNode* root = new TreeNode(10);
    root->Left = new TreeNode(2);
    root->Right = new TreeNode(10);
    root->Left->Left = new TreeNode(20);
    root->Left->Right = new TreeNode(1);
    root->Right->Right = new TreeNode(-25);
    root->Right->Right->Left = new TreeNode(3);
    root->Right->Right->Right = new TreeNode(4);
 
    // Function call
	int maxAns = std::numeric_limits<int>::min();
	findMaxSum(root,maxAns);
    std::cout << "Max path sum is " << maxAns << "\n";
	maxAns = std::numeric_limits<int>::min();
    std::unordered_map<TreeNode*,int>us;
	findMaxSumDP(root,maxAns,us);
	std::cout << "Max path sum DP is " <<  maxAns << "\n";
    return 0;
}