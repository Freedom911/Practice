//Program To Find Loop in a linked list
//using FLoyd's cycle algorithm
//https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

#include <iostream>

struct Node
{
  Node*Next;
  int Data;

  Node(int val)
  {
    Next = NULL;
    Data = val;
  }
};


bool hasCycle(Node *node)
{
  Node *fastPtr = node;

  while(fastPtr != NULL && node != NULL)
  {

    node = node->Next;
    fastPtr = fastPtr->Next;
    if(fastPtr)
      fastPtr = fastPtr->Next;

    if(node == fastPtr)
    {
      return true;
    }

  }

  return false;

}

//List   1->2->1->3->4
//                |__|
int main()
{
  Node *node = new Node(1);
  Node *node1 = new Node(2);
  Node *node2 = new Node(1);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);

  node->Next = node1;
  node1->Next = node2;
  node2->Next = node3;
  node3->Next = node4;
  node4->Next = node3;
  std::cout << "\n Has Cycle === " << hasCycle(node) << "\n";

}
