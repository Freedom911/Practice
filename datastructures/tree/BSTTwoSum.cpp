//Two Sum Problems. Given a Sum check if it can be formed by two nodes
//eg we get 1,2,3,4,5,6
//sum given is 5 possible yes via 1,4 or 2,3
//Solution 1 using inorder traversal
//store in array
//and use hashing to find 2 possible number
//Solution 2 using two counter
//i = 0 and j = 5
//if(arr[i] + arr[j] > sum)
//j--;
//else if(arr[i] + arr[j] < sum_
//i ++;
//else return true
//Time complexity in both cases O(n)
//space complexity in both casesO(n)
//Solution 3 Using concept of bst iterator
//for both reverse and front

#include <iostream>
#include <stack>

struct Tree
{
    int data;
    Tree *left;
    Tree *right;

    Tree(int d):data(d),left(nullptr),right(nullptr){}
};


class Solution
{
    std::stack<Tree*> stNext;
    std::stack<Tree*> stPrev;
    public:
    Solution(Tree *Root)
    {
        PushLeft(Root);
        PushRight(Root);
    }

    bool IsTwoSumPossible(const int &Sum)
    {
       Tree * front = Next();

       Tree * prev = Prev();

       while(front && prev && front != prev)
       {
           int left = front->data;
           int right = prev->data;

           if(left + right == Sum)
           {
             std::cout << "\n FOUND = " << left << " " << right << "\n";
             return true;
           }
           else if(left + right < Sum)
           {
               front = Next();
           }
           else
           {
               prev = Prev();
           }
       }
       return false;
    }

    private:

    //return Next element in inorder manner
    Tree* Next()
    {
        Tree *node = stNext.top();
        stNext.pop();
        //this will push the node andits left
        PushLeft(node->right);

        return node;
    }

    //return prev element in inorder manner
    Tree* Prev()
    {
        Tree *node = stPrev.top();
        stPrev.pop();
        //this will push the node and its right
        PushRight(node->left);

        return node;
    }

    void PushLeft(Tree *Node)
    {

        while(Node != nullptr)
        {
            stNext.push(Node);
            Node = Node->left;
        }
    }

    void PushRight(Tree *Node)
    {
        while(Node != nullptr)
        {
            stPrev.push(Node);
            Node = Node->right;
        }
    }
};


int main()
{
    Tree * Root = new Tree(5);
    Tree * Node1 = new Tree(3);
    Tree * Node2 = new Tree(2);
    Tree * Node3 = new Tree(4);
    Tree * Node4 = new Tree(6);
    Tree * Node5 = new Tree(7);

    Root->left = Node1;
    Node1->left = Node2;
    Node1->right = Node3;
    Root->right = Node4;
    Node4->right = Node5;

    Solution S(Root);

    std::cout << "\n IS SUM = 9 Possible ? = " << S.IsTwoSumPossible(9) << "\n";
}
