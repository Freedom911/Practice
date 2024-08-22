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

//Here the concept is we take help of pre order traversal but reverse it with another stack
//basically post order is reverse of pre order with left and right reverse also
//means PostOrder = LeftRightRoot
//Pre order = Root Left Right
//Post order = reverse of pre order which is right left root
//again reverse right and left or explore right before left we get left right root
void PostOrderTwoStack(BinaryTree* root)
{
	std::stack<BinaryTree*>st1;
	std::stack<int>st2;
	std::cout << "\n Two Stacks Iterative \n";
	
	while(true)
	{
		while(root)
		{
			st2.push(root->data); //cout << root->data just like pre order
			st1.push(root);
			root = root->rightChild; //right instead of left
		}
		
		if(st1.empty()) 
		{
			break;
		}
		
		root = st1.top();
		st1.pop();
		root = root->leftChild;
	}
	
	while(st2.empty() == false)
	{
		std::cout << st2.top() << ",";
		st2.pop();
	}
}


//here in this approach we insert two elements
//when we traverse both child then only we print the node
//so when popped element is different from stack top means 
//we have explored both child ren so we can print the root val
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

//We will Use a marker nullptr so basically when we reach nullptr
//this means we have visited both side
void PostOrderTraversalOptimized(BinaryTree* root)
{
  std::stack<BinaryTree*>st;
  std::cout << "\n Iterative optimized \n";
  if(root)
  st.push(root);
  while(st.size())
  {
    BinaryTree *to = st.top();
    if(to == nullptr)
    {
      st.pop();
      std::cout << st.top()->data << " ";
      st.pop();
      continue;
    }

    st.push(nullptr);
    if(to->rightChild)st.push(to->rightChild);
    if(to->leftChild)st.push(to->leftChild);
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
  PostOrderTwoStack(rootNode);
  PostOrderTraversal(rootNode);
  PostOrderTraversalOptimized(rootNode);
  

}
