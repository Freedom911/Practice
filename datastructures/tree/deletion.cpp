//The Deletion would work like this
//We will replace the content of node to be deleted by the deepest node
//https://www.geeksforgeeks.org/deletion-binary-tree/
#include <iostream>
#include <queue>

template<class T>
struct TreeNode
{
  TreeNode* LeftChild;
  TreeNode* RightChild;
  T Data;

  TreeNode(T Val)
  {
    LeftChild = NULL;
    RightChild = NULL;
    Data = Val;
  }
};

template<class T>
void InorderTraversal(TreeNode<T>*RootNode)
{
  if(RootNode != NULL)
  {
    InorderTraversal(RootNode->LeftChild);
    std::cout << RootNode->Data << ",";
    InorderTraversal(RootNode->RightChild);
  }

}


template<class T>
TreeNode<T>* DeleteNode(TreeNode<T>*RootNode,T val)
{
    //No Element presnet
    if(RootNode == nullptr)
    {
       return nullptr;
    }
   //Step 1 first Target Node
   std::queue<std::pair<TreeNode<T> *,TreeNode<T>*>> q;
   std::pair<TreeNode<T>*,TreeNode<T>*>last;
   last.first = nullptr;
   last.second = nullptr;
   TreeNode<T>* target = nullptr; 

   q.push(std::make_pair(RootNode,nullptr));

   while(q.empty() == false)
   {
     std::pair<TreeNode<T>*,TreeNode<T>*>front = q.front();
     q.pop();
 
     //Step 1 find target Node to delete
     if(front.first->Data == val)
     {
        target = front.first;
     }

     last = front;

     //Step 2 continue to find deepest node
     if(front.first->LeftChild != nullptr)
     {
        q.push(std::make_pair(front.first->LeftChild,front.first));
     }

     if(front.first->RightChild != nullptr)
     {
        q.push(std::make_pair(front.first->RightChild,front.first));
     }
   }

   //Now if we didnt find target node we return root
   if(target == nullptr)
   {
    std::cout << "\n Element not found\n";
    return RootNode;
   }

   //Step 3 now swapping part is done here
   TreeNode<T>*lastNode = last.first;
   TreeNode<T>*lastNodeParent = last.second;

   target->Data = lastNode->Data; //copy data. this is shallow copy if it has been a pointer then we had to use memcpy

    //means iska mai baap h abhi zinda
   if(lastNodeParent)
   {
     //check kon sa element delete karna left ya right most
     if(lastNodeParent->LeftChild == lastNode)
     {
        lastNodeParent->LeftChild = nullptr;
     }
     else
     {
        lastNodeParent->RightChild = nullptr;
     }
     delete lastNode;
   }
   //Anath h ye iska koi mai baap nahi h . ab kuch nahi bacha
   else
   {
    delete lastNode;
    return nullptr;
   }

   return RootNode;


}



//   10
//  20 30
//       40
//delete 20
//  10
// 40 30

int main()
{
  TreeNode<int>*RootNode = new TreeNode<int>(10);
  TreeNode<int>*Node1 = new TreeNode<int>(20);
  TreeNode<int>*Node2 = new TreeNode<int>(30);
  TreeNode<int>*Node3 = new TreeNode<int>(40);

  RootNode->LeftChild = Node1;
  RootNode->RightChild = Node2;
  Node2->RightChild = Node3;

  InorderTraversal(RootNode); //20 10 30 40
  std::cout << "\n Deleting Node 20 \n";
  RootNode = DeleteNode(RootNode,20);
  InorderTraversal(RootNode); //40 10 30
}
