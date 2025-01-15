//I will be presenting two solutions
//Solution 2 doesnt increase height
//2. It basically deletes node by calling recursion
//3. Here also three cases.
//   case 1 no children - Simple return nullptr
//   case 2 one children - Simple return the pointer to that
//   case 3 two children - Find Inorder Next Greater or successor then we replace the deleting node data
// with this next greater node . then we again call the deletion in the subtree but with the replaced node
//eg          10
//          5    20
//        2  6  15    25
//                16 24 27
//we need to delete 10
//then we do find nge which is 15
//we replace 10 with 15
//eg          15
//          5    20
//        2  6  15    25
//                16 24 27
//now in the right side of root we delete 15 .we recursively calls until one child or not child is remainining
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
TreeNode *findNGE(TreeNode* Root)
{
    if(Root == nullptr)
    {
        return nullptr;
    }

    while(Root->left != nullptr)
    {
        Root = Root->left;
    }
    return Root;
}


//this Function deletes Node and return the updated tree
//Hypothesis - this Function Finds Val and deletes from Root and return the udpated Root
TreeNode* DelNode(TreeNode *Root,const int &val)
{
    //base Condition
    if(Root == nullptr)
    {
        return nullptr;
    }

    //Induction - 
    if(Root->val > val)
    {
        //this will Delete node in the left side of val and return the updated pointer
        //we connect with Root->left
       Root->left = DelNode(Root->left,val);
    }
    else if(Root->val < val)
    {
        Root->right = DelNode(Root->right,val);
    }
    else
    {
        //we found the element

        //checking children
        //if left side is null then return right sidepointer
        if(Root->left == nullptr)
        {
            TreeNode*Del = Root->right;
            delete Root;
            return Del;
        }//if right side is null then returnleft side pointer
        else if(Root->right == nullptr)
        {
            TreeNode*Del = Root->left;
            delete Root;
            return Del;
        }
        else
        {
            //means two children. Finding the next greater
            TreeNode *NGE = findNGE(Root->right);

            //swap Root->val with NGE
            Root->val = NGE->val;

            //Continue deletion of right subtree for NGE->val
            //we are connecting right side of Root. as NGE is on right side
            //we will calling delNode with Root->right and for NGE->val
            //till we reach the two base conditions
            Root->right = DelNode(Root->right,NGE->val);
        }
    }
    return Root;//Finally Return Root which is the updated Root
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
    TreeNode* updatedTree = DelNode(root, keyToDelete);
    // Printing the tree after deletion
    std::cout << "Tree After Deletion of " << keyToDelete << " (Inorder Traversal): ";
    printInOrder(updatedTree);
    std::cout << "\n";
}

