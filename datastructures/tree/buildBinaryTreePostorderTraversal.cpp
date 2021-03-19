//Program For Building and printing values of a Binary tree
//
//
//Post Traversal is  Left Right Root
//Here unlike preoder and inorder traversal we visit a node twice
//The processing has to be done only after the second visit
//
//Here we will push element twice so that we can check if element should be printed
//if we have visited twice
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

void PostOrderTraversalRec(BinaryTree *root)
{
  if(root)
  {
    PostOrderTraversalRec(root->leftChild);
    PostOrderTraversalRec(root->rightChild);
    std::cout << root->data << " ";
  }
}

void PostOrderTraversal(BinaryTree *root)
{
  std::stack<BinaryTree*>st;
  std::cout << "\n ITERATIVE \n";
  while(true)
  {
    while(root)
    {
      st.push(root);
      st.push(root);
      root = root->leftChild;
    }

    if(st.empty())
      return;
    root = st.top();
    st.pop();

    //Now Check if the popped element and the top element of stack is same
    //if same means we havent visited right node
    if(!st.empty() && st.top() == root)
      root = root->rightChild;
    else
    {
      std::cout << root->data << " ";
      root = NULL;
    }
  }
}


//Create tree as following
//      10
//    /   \
//   11   12
//  / \   / \
// 13 14 15 16

//Expected Output
//13,14,11,15,16,12,10

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
  PostOrderTraversalRec(rootNode);
  PostOrderTraversal(rootNode);
  

}
