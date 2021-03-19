//Program For Building and printing values of a Binary tree
//
//
//PreOrder Traversal is Root Left Right
//Here the idea is we print value before visiting subchildren
//and the order is first visit root then visit left and then visit right node
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

void preOrderTraversalRec(BinaryTree*root)
{
  if(root)
  {
    std::cout << root->data << " ";
    preOrderTraversalRec(root->leftChild);
    preOrderTraversalRec(root->rightChild);
  }
}

//Non Iterative Way 
//Here the idea is first print element and then traverse deep down to left subtree and 
//when we have reached end take the last element and traverse right and then again
//reach deep down as left subtree
//Choice for Datastrcuture is 
void preOrderTraversal(BinaryTree *root)
{
  std::cout << "\n ITERATIVE TRAVERSAL \n";
  std::stack<BinaryTree*>nodes;
  while(true)
  {
    while(root)
    {
      std::cout << root->data << " ";
      nodes.push(root);
      root = root->leftChild;
    }

    if(nodes.empty())//means no element
      break;

    root = nodes.top();//take the last visited node
    nodes.pop();
    root = root->rightChild;//Now checkc the right child
  }
}


//Create tree as following
//      10
//    /   \
//   11   12
//  / \   / \
// 13 14 15 16


int main()
{
  BinaryTree *rootNode = new BinaryTree(10);
  BinaryTree *node1 = new BinaryTree(11);
  BinaryTree *node2 = new BinaryTree(12);
  BinaryTree *node3 = new BinaryTree(13);
  BinaryTree *node4 = new BinaryTree(14);
  BinaryTree *node5 = new BinaryTree(15);
  BinaryTree *node6 = new BinaryTree(16);
  
  rootNode->leftChild = node1;
  rootNode->rightChild = node2;

  node1->leftChild = node3;
  node1->rightChild = node4;
  
  node2->leftChild = node5;
  node2->rightChild = node6;
  std::cout << "\n RECURSIVE TRAVERSAL \n";
  preOrderTraversalRec(rootNode);//Expected Ouput 10 11 13 14 12 15 16
  preOrderTraversal(rootNode);//Expected Ouput 10 11 13 14 12 15 16
  

}
