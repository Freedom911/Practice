/**
 *
 *  Need to find maximum width of complete Binary Tree. Acomplete tree is a tree
    where all nodes are filled. In last level the nodes are filled from left side
    eg 
       1
     2   3
   4  5
   Is a Complete Binaary tree
    but this
       1
    2    3
       4
    is not

    To Find Width of Binary Tree we can simply Subtract the index of nodes
    . We do level order traversal
    so for first tree we get
    1 - Max Width first - last child + 1 so here it is 1
    2,3 - Max Width  3-2 + 1 = 2
    4,5 - Max width 5-4 + 1 = 2
    We get Max Width = 2
    To get left child we do 2*i + 1 and 2*i + 2 where i starts from 0

    More optimization can be done since we dont need exact index as this can cause overflow
    we require just last level

    So what we do is we subtract min i froma level so here example 2 is having i = 1 and 3 is having i = 2
    for 4 we do i - mini = 1-1 = 0 and we use id = 0 to expand 4 and 5. So 4 = 2*(i-mini) + 1 = 2*0 + 1
    so 4 is at 1 and 5 is at 2
    
 *
 */
 

#include <iostream>
#include <queue>
#include <map>


struct BinaryTree
{
  int data;
  BinaryTree*left;
  BinaryTree*right;

  BinaryTree(int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};


int MaxWidth(BinaryTree* Root)
{
    if(Root == nullptr)
    {
        return 0;
    }
    
    //second element stores i for child calculation index
    std::queue<std::pair<BinaryTree*,int>> q;
    q.push({Root,0});

    int ans = 0;

    while(q.empty() == false)
    {
        int size = q.size();//child size
        int first = 0,last = 0;

        int minVal = q.front().second;

        for(int i = 0; i < size; i++)
        {
            int id = q.front().second - minVal;

            if(i == 0)
                first = id;
            if(i == size- 1)
                last = id;

            BinaryTree* Node = q.front().first;
            q.pop();

            if(Node->left)
                q.push({Node->left,(2*id) + 1});
            if(Node->right)
                q.push({Node->right,(2*id) + 2});
        }
        ans = std::max(ans,last-first + 1);
    }

    return ans;
}

int main()
{
    BinaryTree* root = new BinaryTree(3);
    root->left = new BinaryTree(5);
    root->right = new BinaryTree(1);
    root->left->left = new BinaryTree(6);
    root->left->right = new BinaryTree(2);
    root->right->left = new BinaryTree(0);
    root->right->right = new BinaryTree(8);
    root->left->right->left = new BinaryTree(7);
    root->left->right->right = new BinaryTree(4);


    int width = MaxWidth(root);

    std::cout << "Maximum width of the binary tree is: "
                        << width << std::endl;
}



