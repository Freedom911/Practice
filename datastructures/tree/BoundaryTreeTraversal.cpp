/**
 In Boundary Tree Traversal we first print the left subtree then leaf nodes
 and then right in reverse order.
 Basically we are printing the boundary of tree
 https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/
 Given a Binary Tree, perform the boundary traversal of the tree. 
 The boundary traversal is the process of visiting the 
 boundary nodes of the binary tree in the
 anticlockwise direction, starting from the root.
*/


#include <iostream>
#include <vector>
#include <stack>
struct BinaryTree
{
  int data;
  BinaryTree*leftChild;
  BinaryTree*rightChild;

  BinaryTree(int data)
  {
    this->data = data;
    leftChild = NULL;
    rightChild = NULL;
  }
};

std::ostream & operator <<(std::ostream &out,const std::vector<int> &ans)
{
	out << "[";
	for(int i = 0; i < ans.size(); i++)
	{
		out << ans[i];
		
		if(i + 1 != ans.size())
			out << ",";
	}
	out << "]";
}

//Checks if the node is leaf node or not
bool isLeaf(BinaryTree*Root)
{
	if(Root && Root->leftChild == nullptr && Root->rightChild == nullptr)
	{
		return true;
	}
	
	return false;
}

//1. First is to print the left boundary
void PrintLeft(BinaryTree*Root,std::vector<int> &ans)
{
	Root = Root->leftChild;
	
	while(Root)
	{
		//Check if it is leaf node or not
		//we dont want to include leaf node here as we will print them later
		if(!isLeaf(Root))
		{
			ans.push_back(Root->data);
		}
		
		//now we move to left subtree
		if(Root->leftChild)
		{
			Root = Root->leftChild;
		}
		else
		{
			//else in case we dont have left child we would move to right node
			//and in further loop we again move to left child
			Root = Root->rightChild;
		}
	
	}
}

//2. Hypothesis Print Leaf Node
void PrintLeaf(BinaryTree*Root,std::vector<int> &ans)
{
	//Base Conditions
	if(Root == nullptr)
	{
		return;
	}
	
	if(isLeaf(Root))
	{
		ans.push_back(Root->data);
		return;
	}
	
	//move to left and right  both
	//thats why no else
	if(Root->leftChild)
	{
		PrintLeaf(Root->leftChild,ans);
	}
	
	if(Root->rightChild)
	{
		PrintLeaf(Root->rightChild,ans);
	}
}


//3 Print Right Boundary in reverse order
void PrintRight(BinaryTree*Root,std::vector<int> &ans)
{
	Root = Root->rightChild;
	std::stack<int>s;
	
	while(Root)
	{
		//Check if it is leaf node or not
		//we dont want to include leaf node here as we will print them later
		if(!isLeaf(Root))
		{
			s.push(Root->data);
		}
		
		//now we move to right subtree
		if(Root->rightChild)
		{
			Root = Root->rightChild;
		}
		else
		{
			//else in case we dont have right child we would move to left node
			//and in further loop we again move to right child
			Root = Root->leftChild;
		}
	
	}
	
	while(s.empty() == false)
	{
		ans.push_back(s.top());
		s.pop();
	}
}


//Hypothesis. This function prints the boundary Tree
void PrintBoundary(BinaryTree*Root)
{
	//Initial Conditions
	if(Root == nullptr)
	{
		return;
	}
	
	std::vector<int> ans;
	
	//Check if root node is leaf node or not
	//because in all three nodes we are avoiding root
	//like in print left we move left ,in print right we start from right
	//and in print leaf we print only if is is leaf node
	if(!isLeaf(Root))
	{
		ans.push_back(Root->data);
	}
	
	//1. Print Left
	PrintLeft(Root,ans);
	//2. Print Leaf
	PrintLeaf(Root,ans);
	//3.Print RIght in reverse
	PrintRight(Root,ans);
	
	std::cout << ans;
}


//Create tree as following
//    8
//  3   10
// 1   6  14
//    4 7 13
//Expected ouptut
//8 10 14
//3 6 7
//13 
//1 4
//all in one line
int main()
{
    // Creating a sample binary tree
    BinaryTree* root = new BinaryTree(1);
    root->leftChild = new BinaryTree(2);
    root->rightChild = new BinaryTree(3);
    root->leftChild->leftChild = new BinaryTree(4);
    root->leftChild->rightChild = new BinaryTree(5);
    root->rightChild->leftChild = new BinaryTree(6);
    root->rightChild->rightChild = new BinaryTree(7);
  
   std::cout << "\n Boundary TRAVERSAL \n";
  PrintBoundary(root);

  

}
