#include <iostream>
#include <limits>
#include <unordered_map>

struct Tree
{
	int data;
	Tree* left;
	Tree* right;
	
	Tree(int val)
	{
		data = val;
		left = right = nullptr;
	}
};

//Hypothesis
int solve(Tree* root,int &res)
{
	//Base condition
	if(root == nullptr)
	{
		return 0;
	}
	
	//Induction step
	int l = solve(root->left,res);
	int r = solve(root->right,res);
	
	//two cases when root is involved
	int rootInvolved = std::max(l,r) + 1;
	int rootNotInvolved = l + r + 1; //this would always be bigger than root involved
	res = std::max(res,std::max(rootInvolved,rootNotInvolved));
	
	return rootInvolved;
}

//Hypothesis- No the dp is not there since it is not overlapping. 
int solveDP(Tree* root,int &res,std::unordered_map<Tree*,int>&us)
{
	//Base condition
	if(root == nullptr)
	{
		return 0;
	}
	int l = -1;
	int r = -1;
	if(us.find(root->left) != us.end())
	{
		std::cout << "\n Is Null Left " << (root->left == nullptr) << "\n";
		l =  us[root->left];
	}
	else
	{
		l = solveDP(root->left,res,us);
		us[root->left] = l;		
	}
	
	if(us.find(root->right) != us.end())
	{
				std::cout << "\n Is Null right " << (root->right == nullptr) << "\n";
		r = us[root->right];
	}
	else
	{
		r = solveDP(root->right,res,us);
		us[root->right] = r;
	}
	
	 
	//two cases when root is involved
	int rootInvolved = std::max(l,r) + 1;
	int rootNotInvolved = l + r + 1; //this would always be bigger than root involved
	res = std::max(res,std::max(rootInvolved,rootNotInvolved));
	
	return rootInvolved;
}

int diameter(Tree *root)
{
	int res = std::numeric_limits<int>::min();
	solve(root,res);
	return res;
}

int diameterDP(Tree *root)
{
	int res = std::numeric_limits<int>::min();
	std::unordered_map<Tree*,int>us;
	solveDP(root,res,us);
	return res;
}

int main()
{
	Tree *root = new Tree(1);
	Tree *node1 = new Tree(2);
	Tree *node2 = new Tree(3);
	Tree *node3 = new Tree(4);
	Tree *node4 = new Tree(5);
	root->left = node1;
	root->right = node2;
	node1->left = node3;
	node1->right = node4;

    // Function Call
    std::cout << "Diameter of the given binary tree is "  << diameter(root) << "\n";
	std::cout << "Diameter of the given binary tree is "  << diameterDP(root) << "\n";

    return 0;
}
