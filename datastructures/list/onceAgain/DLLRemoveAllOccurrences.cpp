/**
 * Remove all occurrences of a key in DLL
 */

#include <iostream>


struct Node
{
   int data;
   Node *prev;
   Node *next;

   Node(int val,Node*p = nullptr,Node*n = nullptr)
   {
       data = val;
       prev = p;
       next = n;
   }
};

Node * deleteAllOccurrences(Node* Head, int elem) 
{
    //Base Condition
    if(Head == nullptr)
    {
        return nullptr;
    }

    //Edge case with Head Modification
    while(Head && Head->data == elem)
    {
        Node *toDel = Head;
        Head = Head->next;
        delete toDel;
        if(Head == nullptr)
        {
            return nullptr;
        }
        Head->prev = nullptr;
    }
    return Head;

    //Main Body
    Node* Curr = Head;
    while(Curr)
    {
      if(Curr->data == elem)
      {
          Node*prev = Curr->prev;
          Node*next = Curr->next;
          prev->next = next;
          if(next)
          {
              next->prev = prev;
          }
          delete Curr;
          Curr = next;
      }
      else
      {
          Curr = Curr->next;
      }
    }
    return Head;
}
void Display(Node* Head)
{
    if(Head == nullptr)
    {
        return ;
    }

    std::cout << "Linked List Content = ";
    while(Head)
    {
        std::cout << Head->data << "->";
        Head = Head->next;
    }
    std::cout << "nullptr \n";
}
int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(1);
    Node* node3 = new Node(1);
    Node* node4 = new Node(1);
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node1 = deleteAllOccurrences(node1,1);
    Display(node1);
}
