// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
  Node* next;
  int data;
};
void sortList(Node** head,int detachNode);
// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
  Node* newNode = new Node;
  newNode->next = (*head);
  newNode->data = data;
  (*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
  while (head != NULL)
  {
    cout << head->data;
    if (head->next != NULL)
      cout << " ";
    head = head->next;
  }
  cout<<endl;
}


// Driver code
int main()
{

  int t=0;
  int n = 0;
  cin>>t;
  while(t--)
  {
    Node* head = NULL;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      // push(&head, a);
    }
    for(int i=n-1;i>=0;i--)
    {
      push(&head, arr[i]);
    }
    // printList(head);

    int data;
    std::cout << "\n ENter Data to detach \n";
    std::cin >> data;
    sortList(&head,data);

    printList(head);

  }
  return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:
   struct Node
   {
   Node* next;
   int data;
   }; */

/*Your method shouldn't print anything
  it should transform the passed linked list */
void sortList(Node** head,int detachNodeValue)
{
  if((*head)->next == NULL)
    return;
  Node *headStart = *head;
  Node *prevNode = *head;

  while(headStart != NULL)
  {
    //Deteach A Thread
    if( headStart->data == detachNodeValue)
    {
      Node *tempNode = headStart;

      headStart = tempNode->next;;

      prevNode->next = headStart    ;
      tempNode->next = *head;
      prevNode = *head;
      *head = tempNode;



    }
    else
    {
      prevNode = headStart;
      headStart = headStart->next;
    }
  }
}
