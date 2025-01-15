//Find count of single vlaued subtrees
//eg        5
//       1     5
//     5  5      5
//4 output
//three 5 leave nodes and one 5-5 node
//we simply will do a post order traversal
//Match left and right and increment count
#include <iostream>

struct Tree
{
	 int data;
	 Tree*left;
	 Tree*right;
	 Tree(int val):data(val),left(nullptr),right(nullptr){}
};

void getSingleValued(Tree*Root ,int &count)
{
    if(Root == nullptr)
    {
        return ;
    }

    getSingleValued(Root->left,count);
    getSingleValued(Root->right,count);

    if(Root->left && Root->right && Root->left->data == Root->right->data)
    {
      count++;
    }
    else if(Root->left && Root->right == nullptr)
    {
        count++;
    }
    else if(Root->right && Root->left == nullptr)
    {
        count++;
    }
    else if(Root->right == nullptr && Root->left == nullptr)
    {
        count++;
    }
}

int main()
{
   int count = 0;
    Tree* root        =   new Tree(5);
    root->left        =  new Tree(4);
    root->right       =  new Tree(5);
    root->left->left  =  new Tree(4);
    root->left->right =  new Tree(4);
    root->right->right = new Tree(5);
    getSingleValued(root,count);
    std::cout << "Count of Single Valued Subtrees is " << count << "\n";
}
