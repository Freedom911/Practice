/**
 *
 * https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/
 *
 * Problem Statement: Given two sorted linked lists, merge 
 * them to produce a combined sorted linked list. Return the 
 * head of the final linked list created.
 *
 * Examples
 * Example 1:
 * Input: List1: 2 4 8 10, List2: 1 3 3 6 11 14
 * Output: Combined List: 1 2 3 3 6 8 10 11 14
 *
 * Solution
 *
 * Solution 1 - Using Array
 * Store everything in array. Sort it and create a new linked list with these elements
 * Time Complexity O(n +nlogn + n)
 * Space Complexity O(2n)
 *
 * Solution 2 - Using new linked list
 *
 * Have two pointers head1 and head2 pointing to both list respectively
 *
 * Append in new linked list if head1 data < head2
 *
 * Time Complexity O(n)
 * Space Complexity O(n)
 *
 * Solution 3 - 
 * Changing Links
 * Here we gonna use the dummy node concept and just change the links
 * Initially
 * Dummy node = -1
 * then we compare head1 and head2 if head1 is chota we gonna point to the chota node 
 */
#include <iostream>

struct LinkedList
{
    int data;
    LinkedList*next;

    LinkedList(int val):data(val),next(nullptr){}
};

//Adds remaining nodes to Tail
//Passing reference to a pointer as we want head to become null once it is returned
//same for tail we want to update the tail
void AddPendingNodes(LinkedList*& Tail,LinkedList*&Head)
{
    while(Head)
    {
        Tail->next = Head;
        Head = Head->next;
        Tail = Tail->next;
    }
}

//this Function is responisble for merging two sorted linked list
//and returns the head pointer
LinkedList *MergeTwo(LinkedList*Head1, LinkedList*Head2)
{
    //Check Conditins
    if(Head1 == nullptr && Head2 == nullptr)
    {
        return nullptr;
    }
    else if (Head1 == nullptr)
    {
        return Head2;
    }
    else if (Head2 == nullptr)
    {
        return Head1;
    }

    //Create a Dummy node
    LinkedList* Dummy = new LinkedList(-1);
    LinkedList* Tail = Dummy;

    while(Head1 && Head2)
    {
        if(Head1->data < Head2->data)
        {
            Tail->next = Head1;
            Head1 = Head1->next;
        }
        else
        {
            Tail->next = Head2;
            Head2 = Head2->next;
        }
        Tail = Tail->next;
    }

    AddPendingNodes(Tail,Head1);
    AddPendingNodes(Tail,Head2);

    LinkedList* newHead = Dummy->next;
    delete Dummy;
    return newHead;
}

void Display(LinkedList* Head)
{
    if(Head == nullptr)
    {
        std::cout << " Nullptr \n";
        return;
    }

    std::cout << Head->data << "->";
    Display(Head->next);
}
int main()
{
    LinkedList *node1 = new LinkedList(1);
    LinkedList *node2 = new LinkedList(7);
    LinkedList *node3 = new LinkedList(9);
    node1->next = node2;
    node2->next = node3;
    std::cout << "\n Linked List 1 = " ;
    Display(node1);


    LinkedList *node11 = new LinkedList(2);
    LinkedList *node21 = new LinkedList(5);
    LinkedList *node31 = new LinkedList(41);
    node11->next = node21;
    node21->next = node31;
    std::cout << "\n Linked List 2 = " ;
    Display(node11);

    LinkedList* merged = MergeTwo(node1,node11);
    std::cout << "\n Merged Linked List = \n";
    Display(merged);

}
