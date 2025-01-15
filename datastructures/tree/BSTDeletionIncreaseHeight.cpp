//I will be presenting two solutions
//Solution 1 increase in height
//1. First Solution increases height by one
//2. It basically connects the inorder predecessor with the right child
//3. Here there are three cases.
//   case 1 no children - Simple return nullptr
//   case 2 one children - Simple return the pointer to that
//   case 3 two children - find inorder precessor and connect to right subtree
#include <iostream>

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode {
    // Value of the node
    int val;

    // Pointer to the left child node
    TreeNode* left;
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//This Function find inorder pred
TreeNode *findPred(TreeNode* Root)
{
    if(Root == nullptr)
    {
        return nullptr;
    }

    while(Root->right != nullptr)
    {
        Root = Root->right;
    }
    return Root;
}

//This Function return the next poitner after the Root has been removed
TreeNode *delHelper(TreeNode *Root)
{
    //Case one children
    if(Root->left == nullptr)
    {
        return Root->right;
    }
    if(Root->right == nullptr)
    {
        return Root->left;
    }
    
    TreeNode* right = Root->right;
    TreeNode* preSuc = findPred(Root->left);
    preSuc->right = right;
    return Root->left; //retutn the left side as whole right subtree is gone now
}

//this Function deletes Node and return the updated tree
TreeNode* deleteNode(TreeNode *Root,const int &val)
{
    if(Root == nullptr)
    {
        return nullptr;
    }

    //case handle if root node is to be deleted
    if(Root->val == val)
    {
        TreeNode * temp = Root;
        Root = delHelper(Root);

        delete temp;
        return Root;
    }
    TreeNode* OrigRoot = Root;

    //now first we find and then delete
    while(Root)
    {
        if(Root->val > val)
        {
            //we want tomove left. No need to check for right
            //as right m kabhi hoga hi nahi
            if(Root->left && Root->left->val == val)
            {
                TreeNode *temp = Root->left;
                Root->left = delHelper(Root->left);
                delete temp;
                return OrigRoot;
            }
            else
            {
                //keep moving left
                Root = Root->left;
            }
        }
        else
        {
            //move in right side
            //we want tomove right No need to check for left
            //as left m kabhi hoga hi nahi
            if(Root->right && Root->right->val == val)
            {
                TreeNode *temp = Root->right;
                Root->right = delHelper(Root->right);
                delete temp;
                return OrigRoot;
            }
            else
            {
                //keep moving left
                Root = Root->left;
            }

        }
    }
    std::cout << "\n Element = " << val << " Not Found = \n";
    return OrigRoot;//not found
}

void printInOrder(TreeNode *Root)
{
   if(Root == nullptr)
   {
       return;
   }

   printInOrder(Root->left);
   std::cout << Root->val << ",";
   printInOrder(Root->right);
}



int main()
{
    // Creating a sample tree for testing purposes
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // Printing the original tree
    std::cout << "Original Tree (Inorder Traversal): ";
    printInOrder(root);
    std::cout << "\n";

    // Testing the deleteNode function
    int keyToDelete = 3;
    TreeNode* updatedTree = deleteNode(root, keyToDelete);
    // Printing the tree after deletion
    std::cout << "Tree After Deletion (Inorder Traversal): ";
    printInOrder(updatedTree);
    std::cout << "\n";
}

