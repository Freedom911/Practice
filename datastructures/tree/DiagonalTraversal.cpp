/**
 The Main Idea of DiagonalTraversal is that we try to go to right subtree and
 and print that. and to visit left child after visiting all right we have 
 to remember it so we push left child in a queue before moving right
*/


#include <iostream>
#include <queue>
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


void DiagonalTraversal(BinaryTree*Root)
{
	if(Root == nullptr)
		return;
	BinaryTree*Curr = Root;
	//queue containing Nodes
	std::queue<BinaryTree*>q;
	q.push(Root);
	
	while(q.empty() == false)
	{
		BinaryTree* Node = q.front();
		q.pop();
		
		//visit and print the right hand side only
		while(Node)
		{
			//Before Moving we ought to remember the left child for exploration
			//after we have explored the right hand side
			if(Node->leftChild)
			{
				q.push(Node->leftChild);
			}
			std::cout << Node->data << ",";
			Node = Node->rightChild;
		}
		
	}

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
  BinaryTree *root = new BinaryTree(8);
  BinaryTree *node1 = new BinaryTree(3);
  BinaryTree *node2 = new BinaryTree(10);
  BinaryTree *node3 = new BinaryTree(1);
  BinaryTree *node4 = new BinaryTree(6);
  
  BinaryTree *node5 = new BinaryTree(14);
  BinaryTree *node6 = new BinaryTree(4);
  BinaryTree *node7 = new BinaryTree(7);
  BinaryTree *node8 = new BinaryTree(13);
 
  
  root->leftChild = node1;
  root->rightChild = node2;
  
  node1->leftChild = node3;

  node2->leftChild = node4;
  node2->rightChild = node5;
  
  node4->leftChild = node6;
  node4->rightChild = node7;
  
  node5->leftChild = node8;

  
   std::cout << "\n Diagnoal TRAVERSAL \n";
  DiagonalTraversal(root);

  

}
