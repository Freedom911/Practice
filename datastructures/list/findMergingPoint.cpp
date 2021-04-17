//Program To Find Merging Point for Two Linked lIst
//https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
//We will achieve this O(m+n) where m = length of linked list 1,n=length of linked list 2
//and in o(1) space complexity
//We will fist calculate the diff of both the list's count
//and then we will increment the larger list to that point so that
//from their onwards we can somply have one loop and match both

#include <iostream>
#include <vector>
struct Node
{
  int data;
  Node*next;

  Node(int d = 0)
  {
    data = d;
    next = NULL;
  }
};


unsigned int getTotalNodes(Node *head)
{

  unsigned int count = 0; 
  while(head != NULL)
  {
    count++;
    head = head->next;
  }
  return count;
}


Node *getIntersectingNode(const int &d,Node *biggerList,Node *smallerList)
{
  for(int i = 0; i < d; i++)
  {
    if(biggerList == NULL)
      break;
    biggerList = biggerList->next;
  }

  while(biggerList != NULL && smallerList != NULL)
  {
    std::cout << "\n BIGGER LIST,SMALLER LIST = " << biggerList->data << " " << smallerList->data << "\n";
    //means both node are smae
    if(biggerList == smallerList)
      return biggerList;


    biggerList = biggerList->next;
    smallerList = smallerList->next;
  }

  return NULL;
}

Node * mergingNode(Node*list1,Node*list2)
{
  int countList1 = getTotalNodes(list1);
  int countList2 = getTotalNodes(list2);


  //Means LIst 1 is bigger
  if(countList1 > countList2)
  {

    return getIntersectingNode(countList1 - countList2,list1,list2);

  }
  else
  {
    return getIntersectingNode(countList2 - countList1,list2,list1);
  }


}



Node *createList(const std::vector<int> &elem)
{
  if(elem.size() == 0)
    return NULL;

  Node *head = new Node(elem[0]);
  Node *prev = head;

  for(int i = 1; i< elem.size(); i++)
  {
    Node *elemNode = new Node(elem[i]);
    prev->next = elemNode;
    prev = elemNode;
  }

  return head;
}

void display(Node *head)
{
  std::cout << "\n LIST = ";
  while(head != NULL)
  {
    std::cout << head->data << ",";
    head = head->next;
  }
}

void freeList(Node*head)
{
  while(head != NULL)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
  }

}

//Liunked List 1 = 1,2,3,4,5,6
//Linked list 2 10,11,12,5
//Merge Point 5
int main()
{
  Node*root1 = createList({1,2,3,4,5,6});
  Node*root2 = createList({10,11,12});


  Node *end1 = root1;
  while(end1->next != NULL)
  {
    end1 = end1->next;
  }


  //Now Merge Root2 with 1
  Node *end = root2;
  while(end->next != NULL)
    end = end->next;

  end->next =end1;

  display(root1);
  display(root2);

 Node *mergeNode  = mergingNode(root1,root2);

 if(mergeNode == NULL)
   std::cout << "\n No merging Node Found \n";
 else
   std::cout << "\n Merging Node is = " << mergeNode->data << "\n";



}
