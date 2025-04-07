/**
 * Given a DLL Find all pairs with a given sum
 */

#include <iostream>
#include <vector>

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


std::vector<std::pair<int, int>> findPairs(Node* head, int k)
{
    std::vector<std::pair<int,int>> res;
    if(head == nullptr)
    {
        return res;
    }

    //Using Two Pointer Approach
    Node *start = head;
    Node * end = head;

    while(end->next != nullptr)
    {
        end = end->next;
    }

    while(start->data < end->data) //to avoid overlapp we simply compare data as it is sorted
    {
        int sum = start->data + end->data;

        //Sum formed is less so forward the start pointer as it will have larger element
        if(sum < k)
        {
            start = start->next;
        }
        else if(sum > k)
        {
            end = end->prev;
        }
        else
        {
            //Sum Found
            res.push_back({start->data,end->data});
            std::cout << "\n PAIR = (" << start->data << "," << end->data << ")\n";
            start = start->next;
            end = end->prev;
        }
    }
    return res;

}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(9);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;
    n5->prev = n4;
    auto f = findPairs(n1,5);

  
}
