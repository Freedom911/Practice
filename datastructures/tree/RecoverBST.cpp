//Recover a BST
//In this problem we are given a bst where two nodes are swapped
//eg 
//                  120
//               40      100
//            10  45   80  50
//120 should be at 50 place and vice versa

#include <iostream>
#include <algorithm>
#include <vector>

struct Tree
{
   int data;
   Tree *left;
   Tree *right;

   Tree(int val):data(val),left(nullptr),right(nullptr)
   {

   }
};


void InorderTraversal(Tree*Root,std::vector<int> &v)
{
    if(Root == nullptr)
    {
        return;
    }

    InorderTraversal(Root->left,v);
    v.push_back(Root->data);
    std::cout << Root->data << ",";
    InorderTraversal(Root->right,v);
}

//-------------------------- SOLUTION 1 -----------------------------------------------------------------
//Solution 1 using sorted array concept
//here we sort array and overwrite the tree
//Store result in array
//overrwrite Tree
//time complexity = O(nlogn) and Space Complexity O(n)
void OverwriteInorderTraversal(Tree*Root,const std::vector<int> &v, int &index)
{
    if(Root == nullptr)
    {
        return;
    }

    OverwriteInorderTraversal(Root->left,v,index);
    Root->data = v[index];
    index++;
    OverwriteInorderTraversal(Root->right,v,index);
}

void Solution1(Tree*Root)
{
    std::cout << "\n SOlution 1 = Recover using array Traversal \n";
    std::vector<int> v;
    InorderTraversal(Root,v);
    std::sort(v.begin(),v.end());
    int index = 0;
    OverwriteInorderTraversal(Root,v,index);
}
//-------------------------------------------------------------------------------------------------------


//Solution 2 is to maintain a pointer to prev and swap -------------------------------------------------
//eg we get array as 10 40 45 120 100 80 50
//we check if the prev value > curr then it is anomaly and keep a pointer
//so 1st anomaly is 120 second is 50 and we simply swap
//if adjacent then we dont get second anomaly we just swap anomaly and anomaly + 1
//we do this in inorder
//need to pass by reference first and second as we are modiyign their value and we want them at last
//Time Complexity and Space Complexity is O(n)

void InorderAndRecover(Tree*Root, Tree*Prev, Tree *& first, Tree*& second)
{
    if(Root == nullptr)
    {
        return;
    }
    InorderAndRecover(Root->left,Prev,first,second);
    
    //here we do
    if(Prev && Prev->data > Root->data)//anomalu
      {
          if(first != nullptr)
          {
              second = Root;
          }
          else
          {
              first = Prev;
              second = Root;
          }

      }
    

    Prev = Root;
    InorderAndRecover(Root->right,Prev,first,second);

}

void Solution2(Tree*Root)
{
   std::cout << "\n SOlution 2 = Recover using inorder Traversal \n";
   Tree *prev = nullptr,*first = nullptr,*second = nullptr;
   InorderAndRecover(Root,prev,first,second);
    if(first && second)
    {
        std::swap(first->data,second->data);
    }
}
//--------------------------------------------------------------------------------------------------


//Solution 3 Morris Traversal ---------------------------------------------------------------------
//Third Solution is extension of Solution2 but here we use Morris Inorder Traversal To Further 
//Reduce Space Complexity to O(1)

void SwapCondition(Tree* Root,Tree* prev,Tree*&first, Tree*&second)
{
    if(Root == nullptr)
    {
        return;
    }

    if(prev && prev->data > Root->data)
    {
        if(first != nullptr)
        {
            second = Root;
        }
        else
        {
            first = prev;
            second = Root;
        }
    }

}

void RecoverMorrisTraversal(Tree*Root)
{
    if(Root == nullptr)
    {
        return;
    }
    Tree *prev{},*first{},*second{};

    while(Root)
    {
        if(Root->left == nullptr)
        {
            SwapCondition(Root,prev,first,second);
            prev = Root;
            Root = Root->right;
        }
        else
        {
            Tree *prevSuc = Root->left;
            while(prevSuc && prevSuc->right && prevSuc->right != Root)
            {
                prevSuc = prevSuc->right;
            }

            //Case 1 Link Creation
            if(prevSuc->right == nullptr)
            {
                prevSuc->right = Root;
                Root = Root->left;
            }
            else //destroy link and print
            {
               prevSuc->right = nullptr;
               SwapCondition(Root,prev,first,second);
               prev = Root;
               Root = Root->right;
            }

        }



    }
    if(first && second)
    {
        std::swap(first->data,second->data);
    }

}

void Solution3(Tree*Root)
{
    std::cout << "\n SOlution 3 = Recover using morris Traversal \n";
    RecoverMorrisTraversal(Root);
}

//----------------------------------------------------------------------------------------------------

void RecoverBST(Tree*Root)
{
    //Solution1(Root);
    //Solution2(Root);
    Solution3(Root);
}

int main()
{
    Tree *Root = new Tree(120);
    Tree *Node1 = new Tree(40);
    Tree *Node2 = new Tree(10);
    Tree *Node3 = new Tree(45);
    Tree *Node4 = new Tree(100);
    Tree *Node5 = new Tree(80);
    Tree *Node6 = new Tree(50);

    Root->left = Node1;
    Root->right = Node4;
    Node1->left = Node2;
    Node1->right = Node3;
    Node4->left = Node5;
    Node4->right = Node6;
    
    std::cout << "\n Iniially \n";
    std::vector<int>v;
    InorderTraversal(Root,v);
    RecoverBST(Root);
    std::cout << "\n Finally \n";
    std::vector<int>vs;
    InorderTraversal(Root,vs);

}

