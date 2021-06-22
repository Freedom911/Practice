//Creating Tree from a list
//https://www.geeksforgeeks.org/given-linked-list-representation-of-complete-tree-convert-it-to-linked-representation/
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

struct List
{

  List*next;
  int val;

  List(int data)
  {
    next = nullptr;
    val = data;
  }
};


//Hypothesis
//This function is resposible for creating an inorder tree
//from a list
//This will also work for smaller input. Smaller Input is reduced by 1
//
Node *createInorderTree(List *head,int i)
{
  //Base Condition
  if(head == nullptr)
    return nullptr;

  int j = 0; 

  List *head1 = head;
  while( j < i && head1 != nullptr)
  {
    head1 = head1->next;
  }

  if(head1 == nullptr)
    return nullptr;
  

  Node *node = new Node(head1->val);

  node->left = createInorderTree(head,2*i + 1);
  node->right = createInorderTree(head,2*i + 2);

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
  List *root = new List(1);
  List *node1 = new List(2);
  List *node2 = new List(3);
  List *node3 = new List(4);
  List *node4 = new List(5);
  List *node5 = new List(6);
  root->next = node1;
  node1->next = node2;
 // node2->next = node3;
 // node3->next = node4;
  //node4->next = node5;




  std::cout << "\n Tree is \n";
  inorderTraversal(createInorderTree(root,0));
}
