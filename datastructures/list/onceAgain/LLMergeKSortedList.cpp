/**
 * https://takeuforward.org/linked-list/merge-k-sorted-linked-lists
 *
 * Problem Statement: Given an array of k linked-lists, 
 * each linked-list is sorted in ascending order. 
 * Merge all the linked-lists into one sorted linked-list
 *
 * Solution
 * Solution 1. 
 * Store all elements in set
 * Create  a new list with the elements
 * Time Complexity O(k*nlog(k*n) + k*n)
 * Space Complexity O(k*n)
 *
 * Solution 2
 * We gonna use the concept of merge 2 list
 * We gonna call on every pair
 * Time Complexity - When we merge firsttwo list we get n1+n2,then we 
 * merge n3 then we have n1+n2+n3
 * So T = (n1+n2) + (n1+n2+n3) + (n1+n2+n3+n4) + n1 + n2 + nk
 * let say all n1 n2 are equal to n
 * T = N + 2N + 3N + ... kN
 * T = N(1+2+3+...k)
 * T = N(k(k+1)/2)
 * Space Complexity O(1)
 *
 *
 * Solution 3
 * We gonna use Priority Queue. We store only the head of each list
 * we use min heap and pick the min element
 * after picking we push the next element of the list
 * for example if we pick list 1 head = 1-20-30
 * so we push 20 on a queue
 * So at a time there will be only k elements
 * Also We just do link modification by using the coentp of Dummy Node
 */
#include <iostream>
#include <vector>
#include <queue>

struct LL
{
    int data;
    LL* next;
    LL(int val,LL*nextPtr=nullptr)
    {
        data = val;
        next = nextPtr;
    }
};


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

    if(Head1)
    {
        Tail->next = Head1;//Seedha Join
    }
    else if(Head2)
    {
        Tail->next = Head2;
    }


    LL* newHead = Dummy->next;
    delete Dummy;
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

//This Function is Renspobile for merging K linked lists
LL *MergeKList(std::vector<LL*> vec)
{
    if(vec.size() == 0)
    {
        return nullptr;
    }

    if(vec.size() == 1)
    {
        return vec[0];
    }

    LL*MergedHead = MergeTwo(vec[0],vec[1]);
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



int main()
{
// Create linked lists
    LL* head1 = new LL(2, new LL(4, new LL(6)));
    LL* head2 = new LL(1, new LL(5));
    LL* head3 = new LL(1, new LL(1, new LL(3, new LL(7))));
    LL* head4 = new LL(8);

    // Populate the lists vector
    std::vector<LL*> lists = {head1, head2, head3, head4};

    std::cout << "\n Merging K Lists =";
    //Display(MergeKList(lists));
    Display(MergeKListPQ(lists));
}
