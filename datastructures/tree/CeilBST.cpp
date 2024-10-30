/**
 Program to find ceil of element in binary search tree if not present
 else return accurate result
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
	BinarySearchTree * ceil = nullptr;;
	while(Root)
	{
		if(Root->data == val)
		{
			return Root;
		}
		//Value is greater than root data so we move to right as we know
		//right side will likely contain data
		if(val > Root->data)
		{
			Root = Root->rightChild;
		}
		else
		{
			ceil = Root;
			Root = Root->leftChild;
		}
	}
	
	return ceil;
}


//Hypothesis - This Function Returns Node containing ceil val
BinarySearchTree * SearchBSTRECHelper(BinarySearchTree*Root,const int &val,BinarySearchTree*&ceil)
{
	//Base COnditions
	if(Root == nullptr)
	{
		return nullptr;
	}
	
	if(Root->data == val)
	{
		ceil = Root;
		return Root;
	}
	
	//Induction
	if(val > Root->data)
	{
		return SearchBSTRECHelper(Root->rightChild,val,ceil);
	}
	else
	{
		ceil = Root;
		return SearchBSTRECHelper(Root->leftChild,val,ceil);
	}
	

	
	
}

BinarySearchTree * SearchBSTREC(BinarySearchTree*Root,const int &val)
{
	BinarySearchTree *ceil = nullptr;
	
	SearchBSTRECHelper(Root,val,ceil);
	
	return ceil;
	
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
  
 
  int val = 12;
  BinarySearchTree * searchedNode = SearchBST(rootNode,val);
  if(searchedNode == nullptr)
  {
	  std::cout << "\n Ceil element of = " << val << " Not Found \n";
  }
  else
  {
	std::cout << "\n Finding Element " << val << " CEIL. Found = " << searchedNode ->data <<"\n";
  }


   val = 18;
  searchedNode = SearchBST(rootNode,val);
  if(searchedNode == nullptr)
  {
	  std::cout << "\n Ceil element of = " << val << " Not Found \n";
  }
  else
  {
	std::cout << "\n Finding Element " << val << " CEIL. Found = " << searchedNode ->data <<"\n";
  }
 
  
  std::cout << "\n =====================================RECURSIVE \n";
  val = 12;
  searchedNode = SearchBSTREC(rootNode,val);
  if(searchedNode == nullptr)
  {
	  std::cout << "\n Ceil element of = " << val << " Not Found \n";
  }
  else
  {
	std::cout << "\n Finding Element " << val << " CEIL. Found = " << searchedNode ->data <<"\n";
  }


  val = 6;
  searchedNode = SearchBSTREC(rootNode,val);
  if(searchedNode == nullptr)
  {
	  std::cout << "\n Ceil element of = " << val << " Not Found \n";
  }
  else
  {
	std::cout << "\n Finding Element " << val << " CEIL. Found = " << searchedNode ->data <<"\n";
  }

}