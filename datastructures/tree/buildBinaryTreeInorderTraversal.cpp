//Program For Building and printing values of a Binary tree
//
//
//InOrder Traversal is  Left Root Right
//Very Similar to Preorder Traversal the idea is firs go deep down to left
//and keep pushing into stack then take the top element from stack 
//print it and go to right
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

void InOrderTraversal(BinaryTree *root)
{
  std::cout << "\n Iterative Way  ";
  std::stack<BinaryTree*>st;
  while(true)
  {
    //we will go deep down in the left side in the abyss
    while(root)
    {
      st.push(root);
      root = root->leftChild;
    }

    if(st.empty())
      break;

    root = st.top();
    st.pop();
    std::cout << root->data << " ";
    root = root->rightChild;
  }

}


//Create tree as following
//      10
//    /   \
//   11   12
//  / \   / \
// 13 14 15 16

//Expected Output
//13 11 14 10 15 12 16

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
  InOrderTraversalRec(rootNode);
  InOrderTraversal(rootNode);
  

}
