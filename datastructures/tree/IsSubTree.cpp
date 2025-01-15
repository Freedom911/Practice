//NOt Working
//Given two trees check if  other tree is present in other tree
//like a subtree
//I will give two solution
//both solution involves finding the subtree root node in main tree
//Solution 1 storing in two array and comparing them
// Simple. Time Complexity is O(n)
//Space Complexity O(n)
//Solution 2 Using Morris Traversal 
//We get Time Complexity is O(n)
//Space Complexity O(1)

//Checking if subtree is there in main tree
//I will be giving two solutions
// both solution are similar using traversal
//1st step is to find the node
#include<iostream>

struct Tree
{
	 int data;
	 Tree*left;
	 Tree*right;
	 Tree(int val):data(val),left(nullptr),right(nullptr){}
};

//1st step find and return pointer to node in main tree with the matching value
Tree *findNode(Tree*Main,Tree*Sub)
{
	if(Main == nullptr || Sub == nullptr)
	{
		return nullptr;
	}

	if(Main->data == Sub->data)
	{
		return Main;
	}
	return findNode(Main->left,Sub);
	return findNode(Main->right,Sub);
}


bool MatchTrees(Tree *	MainTree, Tree* SubTree)
{
	//Base COnditions
	if(MainTree == nullptr && SubTree == nullptr)
	{
		return true;
	}
	else if(MainTree == nullptr)
	{
		return false;//Means Main Tree expired
	}
	else if(SubTree == nullptr)
	{
		return true;//means subtree fully covered
	}

	else if(MainTree->data != SubTree->data)
	{
		return false;
	}

	return  MatchTrees(MainTree->left,SubTree->left) && MatchTrees(MainTree->right,SubTree->right);
}

bool MorrisUncleTraversal(Tree * MainTree, Tree* SubTree)
{
	if(MainTree == nullptr && SubTree == nullptr)
	{
		return true;
	}
	else if(MainTree == nullptr)
	{
		return false;
	}
	else if(SubTree == nullptr)
	{
		return true;
	}

    while(MainTree != nullptr)
    {
        if(SubTree == nullptr)
        {
            return true;
        }

        if(SubTree->data != MainTree->data)
        {
            return false;
        }

        //part for Main tree
        if(MainTree->left == nullptr)
        {
            MainTree = MainTree->right;
        }
        else
        {
            Tree *prev = MainTree->left;

            while(prev->right != nullptr && prev->right != MainTree)
            {
                prev = prev->right;
            }

            //case 1 notlink there
            if(prev->right == nullptr)
            {
                //create link
                prev->right = MainTree;
                MainTree = MainTree->left;
            }
            else
            {
                //case 2 link there remove the link and left partexplored move right
                prev->right = nullptr;
                MainTree = MainTree->right;
            }
        }

        if(SubTree->left == nullptr)
        {
            SubTree = SubTree->right;
        }
        else
        {
            Tree *prev = SubTree->left;

            while(prev->right != nullptr && prev->right != SubTree)
            {
                prev = prev->right;
            }

            //case 1 notlink there
            if(prev->right == nullptr)
            {
                //create link
                prev->right = SubTree;
                SubTree = SubTree->left;
            }
            else
            {
                //case 2 link there remove the link and left partexplored move right
                prev->right = nullptr;
                SubTree = SubTree->right;
            }
        }
    }

	if(MainTree == nullptr && SubTree == nullptr)
	{
		return true;
	}
	else if(MainTree == nullptr)
	{
		return false;
	}
	else 
	{
		return true;
	}
}

int main()
{
	Tree *Root1 = new Tree(3);
	Tree *Node1 = new Tree(2);
	Tree *Node2 = new Tree(1);
	Tree *Node3 = new Tree(11);
	Tree *Node4 = new Tree(10);
	Tree *Node5 = new Tree(15);

	Root1->left = Node1;
	Node1->left = Node3;
	Root1->right = Node2;
	Node1->right = Node4;
	Node4->left = Node5;

	Tree *Root2 = new Tree(2);
	Tree *Node21 = new Tree(11);
	Tree *Node22 = new Tree(10);
	Root2->left = Node21;
	Root2->right = Node22;

	Tree * foundPtr = findNode(Root1,Root2);

	if(foundPtr == nullptr)
	{
		std::cout << "\n Not Found == ";
	}
	else
	{
		std::cout << "Using Recursion = " << MatchTrees(foundPtr,Root2) << "\n";
		std::cout << "Using Morris Uncle = " << MorrisUncleTraversal(foundPtr,Root2) << "\n";
	}

}

