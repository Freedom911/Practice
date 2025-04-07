/**
 * Given a singly Linked list reverse it in groups of K
 */

#include <iostream>

struct Node
{
    int data;
    Node*next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

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

//This Function basically returns kth node
Node* getKthNode(Node*head,int k)
{
    if(head == nullptr)
    {
        return head;
    }
    int cnt = 1;
    while(head && cnt < k)
    {
        head = head->next;
        cnt++;
    }
    return head;
}

//this Fnction performs reversal till kth node only
//returns the head of reversed Linked list
Node* RestrictedRev(Node*head,Node*kthNode)
{
    if(head == nullptr || kthNode == nullptr)
    {
        return head;
    }

    Node*prev = nullptr;
    Node*curr = head;

    while(curr)
    {
        Node*next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        if(prev == kthNode)
          break;
    }

    return prev;


}

//This Function Reverses Linked list in groups of K. 
//it firsts get kth node if null then it breaks
Node* kReverse(Node*head,int k)
{
    if(head == nullptr)
    {
        return nullptr;
    }

    Node*curr = head;
    Node* newHead = nullptr;
    while(curr)
    {
        //Get Kth Node
        Node* kthNode = getKthNode(curr,k);
        if(kthNode)
        std::cout << "kth Node = " << kthNode->data << "\n";
        
        //if not in group of k then last set so return
        if(kthNode == nullptr)
        {
            return newHead;
        }
        //Get the next node of kthNode
        Node*next = kthNode->next;

        //Reverse Pointers from curr to kth node
        Node*RevHead = RestrictedRev(curr,kthNode);
        if(newHead == nullptr)
            newHead = RevHead;
        curr->next = next;
        curr = kthNode;

    }

    return newHead;
}

int main() {
    // Create a linked list with
    // values 5, 4, 3, 7, 9 and 2
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    // Print the original linked list
    std::cout << "Original Linked List: ";
    Display(head);

    // Reverse the linked list
    head = kReverse(head, 5);

    // Print the reversed linked list
    std::cout << "Reversed Linked List: ";
    Display(head);

    return 0;
}
