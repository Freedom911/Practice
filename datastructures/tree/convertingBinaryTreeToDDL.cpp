//Program To Convert a binary tree
//to doubly linked list 
//https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/
//We will do inorder traversal and just add nodes
#include <iostream>
#include <stack>

struct DLL
{
  DLL *prev;
  DLL *next;
  int data;

  DLL(int val)
  {
    prev = next = nullptr;
    data = val;
  }

};


struct TreeNode
{
  TreeNode *LeftChild;
  TreeNode *RightChild;
  int data;

  TreeNode(int val)
  {
    LeftChild = nullptr;
    RightChild = nullptr;
    data = val;
  }
};

//Will doo inorder traversal left root right
DLL * CreateDLL(TreeNode *Root)
{
  DLL *head = nullptr;
  DLL *head1 = nullptr;
  std::stack<TreeNode*>st;

  while(true)
  {
    while(Root)
    {
      st.push(Root);
      Root = Root->LeftChild;
    }

    if(st.empty())
      return head1;
    
    Root = st.top();
    st.pop();
    int val = Root->data;
    DLL * Node = new DLL(val);
    if(head == NULL)
    {
      head = Node;
      head1 = head;
    }
    else
    {
      head->next = Node;
      Node->prev = head;
      head = Node;
    }
    Root = Root->RightChild;
  }
}

void TraverseDLL(DLL*Node)
{
  std::cout << "DLL TRAVERSING \n\n";
  while(Node != nullptr)
  {
    std::cout << Node->data << " " << ",ADDRESS = " << Node << " ";
    Node = Node->next;
  }

}

int main()
{
  TreeNode *Root = new TreeNode(10);
  TreeNode *Node = new TreeNode(12);
  TreeNode *Node1 = new TreeNode(15);
  TreeNode *Node2 = new TreeNode(25);
  TreeNode *Node3 = new TreeNode(30);
  TreeNode *Node4 = new TreeNode(36);
  Root->LeftChild = Node;
  Root->RightChild = Node1;
  Node->LeftChild = Node2;
  Node->RightChild = Node3;
  Node1->LeftChild = Node4;

  TraverseDLL(CreateDLL(Root));

}
