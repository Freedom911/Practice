/**
 The Main Idea of Morris Traversal is that it can traverse tree in O(1) space complexity
 It uses the concept of Threaded Tree where to traverse the Null pointer of leaf node1
 is made to point to successor. 
 We can traverse in Inorder,PreOrder and post order
 In Morris Traversal we modify the structure of Binary Tree by making the leaf node1
 null pointer point to inorder successor
 Remember the inorder successor of a node is the right most node of the left subtree of that
 node.
 
 In Post order morris traversal we do ulta that is we move to right instead of left
 It is mirror image of pre order. we push ans in array and then reverse
 */


#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
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

std::ostream & operator << (std::ostream &out,const std::vector<int> &v)
{
	out << "[";
	for (int i = 0; i < v.size(); i++)
	{
		out << v[i];
		
		if(i + 1 != v.size())
			out << ",";
	}
	return out;
}

void MorrisTraversal(BinaryTree*Root)
{
	BinaryTree*Curr = Root;
	//the vector here will be considered as part of answer so 
	//it wont contribute to space complexity
	std::vector<int>vs;
	
	while(Curr)
	{
		//if There is no right child then we simply print the curr node and move to left
		if(Curr->rightChild == nullptr)
		{
			//std::cout << Curr->data << ",";
			vs.push_back(Curr->data);
			Curr = Curr->leftChild;
		}
		else
		{

			BinaryTree*Prev = Curr->rightChild;
			
			while(Prev->leftChild != nullptr && Prev->leftChild != Curr)
				Prev = Prev->leftChild;
			
			//two cases arise
			//case 1. Prev Left is null this means the link is not there so we create
			if(Prev->leftChild == nullptr)
			{
				Prev->leftChild = Curr;
				
				//std::cout << Curr->data << ","; //
				vs.push_back(Curr->data);
				Curr = Curr->rightChild;//explore right subtree now
			}
			
			//case 2 deletion of link. Means link already there
			else
			{
				//now we need to delete the link and move to left subtree
				Prev->leftChild = nullptr;

				
				//Now explore left subtree
				Curr = Curr->leftChild;
			}
		}
			
	}
	
	 //time complexity is O(n) space is O(1)
	 std::reverse(vs.begin(), vs.end());
	 
	 std::cout << vs;
}

void PostOrderTraversalRec(BinaryTree *root)
{
  if(root)
  {
    PostOrderTraversalRec(root->leftChild);
    PostOrderTraversalRec(root->rightChild);
    std::cout << root->data << " ";
  }
}

//Create tree as following
//      1
//    /   \
//   2     3
//  / \   / \
// 		  4 5

//expected Post order left right root
//2 4 5 3 1
int main()
{
  BinaryTree *rootNode = new BinaryTree(1);
  BinaryTree *node1 = new BinaryTree(2);
  BinaryTree *node2 = new BinaryTree(3);
  BinaryTree *node3 = new BinaryTree(4);
  BinaryTree *node4 = new BinaryTree(5);
 
  
  rootNode->leftChild = node1;
  rootNode->rightChild = node2;

  node2->leftChild = node3;
  node2->rightChild = node4;
 
  //2 4 5 3 1
  std::cout << "\n Post TRAVERSAL \n";
  PostOrderTraversalRec(rootNode);
  
   std::cout << "\n Morris Post Order TRAVERSAL \n";
  MorrisTraversal(rootNode);

  

}