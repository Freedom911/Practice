/**
 * Given A sorted DLL Remove any Duplicates
 */

#include <iostream>

struct Node
{
  int data;
  Node* prev;
  Node* next;

  Node(int val)
  {
    data = val;
    prev = next = nullptr;
  }
};


Node * removeDuplicates(Node *head)
{
    Node *curr = head;

    while(curr)
    {
        Node*currNext = curr->next;

        while(currNext && currNext->data == curr->data)
        {
            //remove Duplicates
            Node*prev = currNext->prev;
            Node*next = currNext->next;
            prev->next = next;
            if(next)
            {
                next->prev = prev;
            }
            delete currNext;
            currNext = next;
        }

        curr = curr->next;
    }
    return head;
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
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(2);
    Node *node4 = new Node(2);
    Node *node5 = new Node(3);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    Display(node1);

    Node* head = removeDuplicates(node1);
    Display(head);

}
