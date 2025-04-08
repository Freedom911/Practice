/**
 * https://takeuforward.org/data-structure/flattening-a-linked-list/
 *
 * Problem Statement: Given a linked list containing ‘N’ head nodes 
 * where every node in the linked list contains two pointers:
 * ‘Next’ points to the next node in the list
 * ‘Child’ pointer to a linked list where the current node is the head
 *
 * Each of these child linked lists is in sorted order and connected by a 
 * 'child' pointer. My task is to flatten this linked list such that all 
 * nodes appear in a single layer or level in a 'sorted order'.
 * It can be all nodes appear in child manner or next manner
 *
 * we will use child manner like vertical direction
 *
 * Solution 
 * The Problem appears Similar to merging K sorted linked list
 */

#include <iostream>
#include <vector>
#include <queue>

struct LL
{
    int data;
    LL* next;
    LL* child;
    LL(int val,LL*nextPtr=nullptr,LL*childPtr=nullptr)
    {
        data = val;
        next = nextPtr;
        child = childPtr;
    }
};



//Adds remaining nodes to Tail
//Passing reference to a pointer as we want head to become null once it is returned
//same for tail we want to update the tail
void AddPendingNodes(LL*& Tail,LL*&Head)
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
LL *MergeTwo(LL*Head1, LL*Head2)
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
    LL* Dummy = new LL(-1);
    LL* Tail = Dummy;

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

    LL* newHead = Dummy->next;
    delete Dummy;
    return newHead;
}


//This Function Flattens
LL *Flattens(LL*Head)
{
    if(Head == nullptr)
    {
        return nullptr;
    }
    if(Head->next == nullptr)
    {
        return Head;
    }

    LL*MergedHead = MergeTwo(Head,Head->next);
    for(int i = 2; i < vec.size(); i++)
    {
        MergedHead = MergeTwo(MergedHead,vec[i]);
    }
    return MergedHead;
}

//This Function Is renspobile for Merging K lists using PQ
LL*MergeKListPQ(std::vector<LL*> vec)
{

    if(vec.size() == 0)
    {
        return nullptr;
    }

    if(vec.size() == 1)
    {
        return vec[0];
    }

    std::priority_queue<std::pair<int,LL*>,std::vector<std::pair<int,LL*>>,
                        std::greater<std::pair<int,LL*>>>pq;

    LL *dummy = new LL(-1);
    LL* tail = dummy;
    for(int i = 0; i < vec.size(); i++)
    {
        pq.push({vec[i]->data,vec[i]});
    }

    while(pq.empty() == false)
    {
      LL* topElement = pq.top().second;
      pq.pop();
      tail->next = topElement;
      if(topElement->next)
      {
          pq.push({topElement->next->data,topElement->next});
      }
      tail = tail->next;
    }
    LL *newHead = dummy->next;
    delete dummy;
    return newHead;

}

 void Display(LL* Head)
 {
	 if(Head == nullptr)
	 {
		 std::cout << " Nullptr \n";
		 return;
	 }
	 
	 std::cout << Head->data << "->";
	 Display(Head->next);
 }

