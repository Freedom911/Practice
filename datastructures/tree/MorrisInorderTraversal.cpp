/**
 The Main Idea of Morris Traversal is that it can traverse tree in O(1) space complexity
 It uses the concept of Threaded Tree where to traverse the Null pointer of leaf node1
 is made to point to successor. 
 We can traverse in Inorder,PreOrder and post order
 In Morris Traversal we modify the structure of Binary Tree by making the leaf node1
 null pointer point to inorder successor
 Remember the inorder successor of a node is the right most node of the left subtree of that
 node.
 */


#include <iostream>
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


void InOrderTraversalRec(BinaryTree *root)
{
  if(root)
  {
    InOrderTraversalRec(root->leftChild);
    std::cout << root->data << " ";
    InOrderTraversalRec(root->rightChild);
  }
}

void MorrisTraversal(BinaryTree*Root)
{
	BinaryTree*Curr = Root;
	
	while(Curr)
	{
		//if There is no left child then we simply print the curr node and move to right
		if(Curr->leftChild == nullptr)
		{
			//right pointer would be pointing to inorder successor
			std::cout << Curr->data << ",";
			Curr = Curr->rightChild;
		}
		else
		{
			//we need to find inorder successor of the curr node
			//which is equal to right most node of the left subtree of curr node
			BinaryTree*Prev = Curr->leftChild;
			
			//Means we have reached the right most node
			//or the the right pointer is pointing to the same curr node
			//in that case we have to move right and delete the link
			while(Prev->rightChild != nullptr && Prev->rightChild != Curr)
				Prev = Prev->rightChild;
			
			//two cases arise
			//case 1. Prev right is null this means the link is not there so we create
			if(Prev->rightChild == nullptr)
			{
				Prev->rightChild = Curr;
				Curr = Curr->leftChild;//explore left subtree now
			}
			
			//case 2 deletion of link. Means link already there
			else
			{
				//now we need to delete the link and move to right subtree
				Prev->rightChild = nullptr;
				//Before Moving we print the data as the left part is done
				//we print root as in inorder traversal which is left,root,right
				std::cout << Curr->data << ","; //
				
				//Now explore right subtree
				Curr = Curr->rightChild;
			}
		}
			
	}
}

//Create tree as following
//      1
//    /   \
//   2     3
//  / \   / \
// 		  4 5

//Expected Output
//13,14,11,15,16,12,10

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
 
  //expected 2 1 4 3 5
  std::cout << "\n Inorder TRAVERSAL \n";
  InOrderTraversalRec(rootNode);
  
   std::cout << "\n Morris Inorder TRAVERSAL \n";
  MorrisTraversal(rootNode);

  

}
