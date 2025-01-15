//Program to implement BST Iterator
//The iterator should provide following functionality
//hasNext() if next node is avaiable in inorder manner
//next() returns value to next tree node in inorder manner
//Solution 1 naive solution
//store BST in array 
//1 2 3 4 5 6 7 8 9 10
//and when we do next we return the next element from array
//by keeping a counter
//Totla Time and SpaceComplexity is O(n)
//other solution is to use one stack.
//one stack keep pushing left elements on stack.
//when asked next is called we take top element from stack and push its right
//and then again push left elements
//eg      7
//      3
//    2  5
//   1  4 6 
//Stack [7,3,2,1]
//top element is 1 print one and move right
//then top element is 2 print 2 and move right
//then  top element is 3 print 3 and move right and keep pushing left
//push 5 and 4 so stack becomes[7,5,4] and so on

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
    std::stack<Tree*> st;
    public:

    Solution(Tree *Root)
    {
        Push(Root);
    }
    //Checks if there is next element or not
    bool hasNext()
    {
        return st.empty() == false;
    }

    //return Next element in inorder manner
    int Next()
    {
        int val = st.top()->data;
        Tree *node = st.top();
        st.pop();
        //this will push the node andits left
        Push(node->right);

        return val;
    }

    private:
    void Push(Tree *Node)
    {

        while(Node != nullptr)
        {
            st.push(Node);
            Node = Node->left;
        }
    }
};


int main()
{
    Tree *Root = new Tree(7);
    Tree *Node1 = new Tree(3);
    Tree *Node2 = new Tree(2);
    Tree *Node3 = new Tree(1);
    Tree *Node4 = new Tree(6);
    Tree *Node5 = new Tree(5);
    Tree *Node6 = new Tree(4);
    Tree *Node7 = new Tree(10);
    Tree *Node8 = new Tree(9);
    Tree *Node9 = new Tree(8);

    Root->left = Node1;
    Node1->left = Node2;
    Node2->left = Node3;

    Node1->right = Node4;
    Node4->left = Node5;
    Node5->left = Node6;

    Root->right = Node7;
    Node7->left = Node8;
    Node8->left = Node9;

    Solution S(Root);

    std::cout << " Has Next = " << S.hasNext() << "\n";
    int i = 0;
    while( i < 10)
    {
        std::cout << S.Next() << " " ;
        i++;
    }
    std::cout << " Has Next = " << S.hasNext() << "\n";
}
