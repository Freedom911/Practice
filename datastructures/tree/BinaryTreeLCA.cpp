/**
 Given a Tree and two values we want to find LCA of two nodes.
 1st Approach is to use our preious knowldge of RootToNodePath .
 Basically we form path for two nodes and store in two array.
 WE match array one by one.we match till we have common elements
 as soon as we get a mismatch we return the last matched element. This is the LCA
 
 This approach requires two time traversal O(2n) and require o(n) space
 
 eg
       1
	  2 3
	  
	  LCA(2,3)
	  Path of 2 is [1,2] stored in array
	  Path of 3 is [1,3]
	  we match both array
	  1 is common 2 and 3 mismatch so we return 1. This is the LCA also
	  
	  
  2nd Approach - SIngle Pass Space Optimized approach
  Basically the thing is same we do pre order traversal only
  the LCA(a,b) is a node whose left and right side contains a and back
  
  so in base condition we take two more condition
  if(root == nullptr //standard || root->data == n1 || root->data == n2)
  {
	  return root; //we return the pointer and wont explore further
  }
  
  for eg 1
        2 3
  here LCA(2,3)
  we see for 2 it returns 2 pointer similarly for 3
  so for 1 we have both left and right side not null
  
  if the value doesnt match we ultimtaly return nullptr
 */


#include <iostream>
#include <queue>
#include <map>


struct BinaryTree
{
  int data;
  BinaryTree*left;
  BinaryTree*right;

  BinaryTree(int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

//Hypothesis - This Function Prints Root to node and returns true if path found
//false otherwise. Maintains path in ans
bool PrintRootToNode(BinaryTree *Root,std::vector<int> & ans,const int &val)
{
	//Base conditions
	//1 if root is null then we didnt find the path so we return null
	if(Root == nullptr)
	{
		return false;
	}
    
	//Push Path in vector
	ans.push_back(Root->data);
	
	//if Elem found we return the path
	if(Root->data == val)
	{
		return true;
	}


	//Induction Step
    //if found anywhere we return the ans containing path and return true
	if(PrintRootToNode(Root->left,ans,val) ||
	   PrintRootToNode(Root->right,ans,val))
	   {
		   return true;
	   }
	   
	//otherwise we pop it
	ans.pop_back();
	
	return false; // oh oh we didnt find the element
	
}


//APproach one using two pass

int  findLCAV1(BinaryTree*Root,int n1,int n2)
{
	if(Root == nullptr)
	{
		return -1;
	}
	
	std::vector<int> v1,v2;
	PrintRootToNode(Root,v1,n1);//path for n1
	PrintRootToNode(Root,v2,n2);//Path for n2
	int i = 0;
	for(i = 0; i < v1.size()  && i < v2.size(); i++)
	{

		if(v1[i] != v2[i])
		{
			if(i > 0)
			{
				return v1[i-1];//return last matched i
			}
			else
			{
				std::cout << "\n LCA not Found = \n";;
				return -1;
			}
		}
	}
	return v1[i-1]; //basically return the last matched element
}


//2nd Approach Optimized One pass no space

//Hypothesis This Function returns LCA of n1 and n2
BinaryTree *  findLCAV2Helper(BinaryTree*Root,int n1,int n2)
{
	//Base Condition
	if(Root == nullptr || Root->data == n1 || Root->data == n2)
	{
		return Root; //dont explore further
	}
	
	//Induction Step
	//explore both side
	BinaryTree *leftSub = findLCAV2Helper(Root->left,n1,n2);
	BinaryTree *rightSub = findLCAV2Helper(Root->right,n1,n2);
	
	//node found with both side as not null we found the lca
	if(leftSub && rightSub)
	{
		return Root;
	}
	
	else 
	{
		//else we explore the side which is not null. Since that side is more promissing
		//and also we havent explore that side complelty because as soon as we get the element
		//we return without exploring further. Nulll wali side toh already explored
		return leftSub ? leftSub : rightSub;
	}
}


int  findLCAV2(BinaryTree*Root,int n1,int n2)
{
	BinaryTree * Node = findLCAV2Helper(Root,n1,n2);
	
	if(Node != nullptr)
	{
		return Node->data;
	}
	else
	{
				std::cout << "\n LCA not Found = \n";;
				return -1;
	}
}

int main()
{


	
	
	BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);
    
	std::cout << "\nLCA Version 1 \n";
    std::cout << "LCA(4, 5) = " << findLCAV1(root, 4, 5) << std::endl;
    std::cout << "LCA(4, 6) = " << findLCAV1(root, 4, 6) << std::endl;
    std::cout << "LCA(3, 4) = " << findLCAV1(root, 3, 4) << std::endl;
    std::cout << "LCA(2, 4) = " << findLCAV1(root, 2, 4) << std::endl;
	
	std::cout << "\nLCA Version 2 \n";
    std::cout << "LCA(4, 5) = " << findLCAV2(root, 4, 5) << std::endl;
    std::cout << "LCA(4, 6) = " << findLCAV2(root, 4, 6) << std::endl;
    std::cout << "LCA(3, 4) = " << findLCAV2(root, 3, 4) << std::endl;
    std::cout << "LCA(2, 4) = " << findLCAV2(root, 2, 4) << std::endl;

}
