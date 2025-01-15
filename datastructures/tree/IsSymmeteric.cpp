//Check if two trees are symmetric of each other
// basically both the trees should be mirror image
//eg 1
//  2 3
// and
//  1
// 3 2
//are symmetric
//we will use two solution
//1st using recursion and
//second using traveral
#include <iostream>

struct Tree
{
    Tree*Left;
    Tree*Right;
    int val;

    Tree(int val)
    {
        this->val = val;
        Left  = nullptr;
        Right = nullptr;
    }
};

//Solution 1 using Recursion
bool isSymmetric(Tree*Node1,Tree*Node2)
{
    if(Node1 == nullptr && Node2 == nullptr)
    {
        return true;
    }
    //only one of them is false so not a symmetric tree
    else if(Node1 == nullptr || Node2 == nullptr)
    {
        return false;
    }

    return Node1->val == Node2->val && isSymmetric(Node1->Left,Node2->Right) 
        && isSymmetric(Node1->Right, Node2->Left);
}

//Solution 2 using Traversal
//if we obsver the above tree we have inorder traversal for 1st tree as 2 1 3 and for 2nd tree we have 3 1 2
//so a tree is symmetric to other tree if inorder traverrsal is equal to reverse(inorder traversal of 2nd tree)
//we shall use morris traversal for best answer related to sapce complexity

bool isSymmetricMorris(Tree *Node1, Tree * Node2)
{
    if(Node1 == nullptr && Node2 == nullptr)
    {
        return true;
    }
    //only one of them is false so not a symmetric tree
    else if(Node1 == nullptr || Node2 == nullptr)
    {
        return false;
    }
    //inorder           //reverse inorder
    while(Node1 != nullptr && Node2 != nullptr)
    {
        //value doesnt match so not a symmetric tree
        if(Node1->val != Node2->val)
        {
            return false;
        }

        //for tree 1
        if(Node1->Left == nullptr)
        {
            Node1 = Node1->Right;
        }
        else
        {
            Tree *prevSuc = Node1->Left;
            //finding inorder predcessor
            while(prevSuc->Right && prevSuc->Right != Node1)
            {
                prevSuc = prevSuc->Right;
            }

            //case 1 link not created so we create
            if(prevSuc->Right == nullptr)
            {
                prevSuc->Right = Node1;
                Node1 = Node1->Left;
            }
            else //Case 2 link there we delete
            {
                prevSuc->Right = nullptr;
                Node1 = Node1->Right;
            }

        }

        //for tree 2 we have reverse
        if(Node2->Right == nullptr)
        {
            Node2 = Node2->Left;
        }
        else
        {
            //jsut next successor
            Tree *nextSuc = Node2->Right;

            while(nextSuc->Left && nextSuc->Left != Node2)
            {
                nextSuc = nextSuc->Left;
            }
            //case 1 link not there so we create
            if(nextSuc->Left == nullptr)
            {
                nextSuc->Left = Node2;
                Node2 = Node2->Right;
            }
            else //case 2 link there we delete
            {
                nextSuc->Left = nullptr;
                Node2 = Node2->Left;//processing finished for right side so move left

            }

        }
    }

    if(Node1 == nullptr && Node2 == nullptr)
        return true;

    return false;

}


int main()
{
    // Representation of input binary tree 1
    //        1
    //       / \
    //      3   2
    //          / \
    //         5   4
    Tree* root1 = new Tree(1);
    root1->Left = new  Tree(3);
    root1->Right = new Tree(2);
    root1->Right->Left = new  Tree(5);
    root1->Right->Right = new Tree(4);

    // Representation of input binary tree 2 (mirror)
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Tree* root2 = new Tree(1);
    root2->Left = new Tree(2);
    root2->Right = new Tree(3);
    root2->Left->Left = new  Tree(4);
    root2->Left->Right = new Tree(5);

    if (isSymmetric(root1, root2))
        std::cout << "true\n";
    else
        std::cout << "false\n";

    if (isSymmetricMorris(root1, root2))
        std::cout << "true\n";
    else
        std::cout << "false\n";

}
