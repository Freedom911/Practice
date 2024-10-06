
/**
 * Statement - Given a binary tree which is complete. 
 * Find the Number of nodes
 *
 * we can simple do level order traversal or any other traversal 
 * or we can use the formula which is used for full binary tree
 *
 * which is 2^h -1 where h is the height
 *
 * so basically we will try to solve for left subtree and right subtree and check if the tree is complete
 * we do this by comparing left and right height
 *
 * if equal then 2^h -1 else we recursively solve for left subtree and right subtree 
 * and we do this 1 + count(root->left) + count(root->right)
 */
#include <iostream>
#include <queue>
#include <cmath>
struct Tree
{
   int data;
   Tree* left;
   Tree* right;

   Tree(int val):data{val},left{nullptr},right{nullptr}
   {

   }
};


int levelOrderCount(Tree*Root)
{
    if(Root == nullptr)
    {
        return 0;
    }

    int count = 0;

    std::queue<Tree*>q;
    q.push(Root);

    while(q.empty() == false)
    {
       count++;
       Tree*Node = q.front();

       q.pop();
       if(Node->left)
       {
           q.push(Node->left);
       }

       if(Node->right)
       {
           q.push(Node->right);
       }
    }
    return count;
}

int getHeightOneSide(Tree*Root,bool isRight)
{
    if(Root == nullptr)
    {
        return 0;
    }

    int height = 0;
    while(Root)
    {
        height++;

        Root = isRight ? Root->right : Root->left;
    }

    return height;
}

//Second Method
//Hypothesis - This method returns count of node
int countRec(Tree*Root)
{
    //base condigion
    if(Root == nullptr)
    {
        return 0;
    }

    int lh = getHeightOneSide(Root,false);
    int rh = getHeightOneSide(Root,true);
   
    //Complete Binary Tree so using formula
    if(lh == rh)
    {
        return std::pow(2,lh) - 1;
    }

    return 1 + countRec(Root->left) + countRec(Root->right);
}

int main()
{
   Tree *Root = new Tree(0);
   Tree *Node1 = new Tree(1);
   Tree *Node2 = new Tree(2);
   Tree *Node3 = new Tree(3);
   Tree *Node4 = new Tree(4);
   Tree *Node5 = new Tree(5);


   Root->left = Node1;
   Root->right = Node2;
   Node2->left = Node3;

   Node1->left = Node4;
   Node1->right = Node5;

   std::cout << "\n Iterative sol = " << levelOrderCount(Root) << "\n";
   std::cout << "\n Rec = " << countRec(Root) << "\n";
}
