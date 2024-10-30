/**
 Program to search element in binary search tree Both Iterative and Rec
 */


#include <iostream>
#include <stack>
struct BinarySearchTree
{
  int data;
  BinarySearchTree*leftChild;
  BinarySearchTree*rightChild;

  BinarySearchTree(int data)
  {
    this->data = data;
    leftChild = NULL;
    rightChild = NULL;
  }
};

BinarySearchTree * SearchBST(BinarySearchTree*Root,const int &val)
{
	if(Root == nullptr)
	{
		return nullptr;
	}
	
	while(Root && Root->data != val)
	{
		//Value is greater than root data so we move to right as we know
		//right side will likely contain data
		if(val > Root->data)
		{
			Root = Root->rightChild;
		}
		else
		{
			Root = Root->leftChild;
		}
	}
	
	return Root;
}

//Hypothesis - This Function Returns Node containing value
BinarySearchTree * SearchBSTREC(BinarySearchTree*Root,const int &val)
{
	//Base COnditions
	if(Root == nullptr)
	{
		return nullptr;
	}
	
	if(Root->data == val)
	{
		return Root;
	}
	
	//Induction
	if(val > Root->data)
	{
		return SearchBSTREC(Root->rightChild,val);
	}
	else
	{
		return SearchBSTREC(Root->leftChild,val);
	}
	
	
	
}


//Create tree as following
//      10
//    /   \
//   7     13
//  / \   / \
// 		  11 15

int main()
{
  BinarySearchTree *rootNode = new BinarySearchTree(10);
  BinarySearchTree *node1 = new BinarySearchTree(7);
  BinarySearchTree *node2 = new BinarySearchTree(13);
  BinarySearchTree *node3 = new BinarySearchTree(11);
  BinarySearchTree *node4 = new BinarySearchTree(15);
 
  
  rootNode->leftChild = node1;
  rootNode->rightChild = node2;

  node2->leftChild = node3;
  node2->rightChild = node4;
  
  int val = 15;
  std::cout << "\n Finding Element " << val << " . Found ? " << (SearchBST(rootNode,val) != nullptr) << "\n";
  val = 8;
  std::cout << "\n Finding Element " << val << " . Found ? " << (SearchBST(rootNode,val) != nullptr) << "\n";
  
  std::cout << "\n RECURSIVE \n";
  val = 15;
  std::cout << "\n Finding Element " << val << " . Found ? " << (SearchBSTREC(rootNode,val) != nullptr) << "\n";
  val = 8;
  std::cout << "\n Finding Element " << val << " . Found ? " << (SearchBSTREC(rootNode,val) != nullptr) << "\n";

}