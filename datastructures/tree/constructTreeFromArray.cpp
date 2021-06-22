//Creating Tree from an array in inorder manner
//https://www.geeksforgeeks.org/construct-complete-binary-tree-given-array/
//Here The Concept is for parent index i left child is at 2i + 1 amd right
//child will be at 2i + 2. Will follow Recursion

#include <iostream>
#include <vector>

struct Node
{
  Node*left;
  Node*right;
  int val;

  Node(int data)
  {
    left = nullptr;
    right = nullptr;
    val = data;
  }
};


//Hypothesis
//This function is resposible for creating an inorder tree
//from an array for element i
//This will also work for smaller input. Smaller Input is reduced by 1
//
Node *createInorderTree(std::vector<int> ar,int i)
{
  //Base Condition
  if(i >= ar.size())
    return nullptr;

  Node *node = new Node(ar[i]);

  node->left = createInorderTree(ar,2*i + 1);
  node->right = createInorderTree(ar,2*i + 2);

  return node;
}

void inorderTraversal(Node *root)
{
  if(root)
  {
    inorderTraversal(root->left);
    std::cout << root->val << "\n";
    inorderTraversal(root->right);
  }
}

int main()
{
  std::vector<int> ar {1,2,3,4,5,6};
  std::cout << "\n Tree is \n";
  inorderTraversal(createInorderTree(ar,0));
}
