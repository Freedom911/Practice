/**
 * Statement - Given a binary tree. Find the max time/distance we
 * get while burning nodes from target nodes
 *
 * eg 
 *
 *           1
 *         2   3
 *            4 
 *           5
 * Given Target = 2
 *
 * The Problem is similar to Print Nodes at kth Distance. Here there is no k
 * so no check of k we just need to return the value of last level which will be maximum'
 *
 * Here we will use the same code
 *
 * we will use recursive solution as well . the main logic would be here that we will find 
 * the max depth only the variation is that we have three children
 */
#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>

struct Tree
{
   int data;
   Tree* left;
   Tree* right;

   Tree(int val):data{val},left{nullptr},right{nullptr}
   {

   }
};

//This Function creates parent pointer
void CreateParentPtr(Tree*Root,std::unordered_map<Tree*,Tree*> &us)
{
    //check Conditions
    if(Root == nullptr)
    {
        return ;
    }

    std::queue<Tree*>q;
    q.push(Root);

    while(q.empty() == false)
    {
        Tree* node = q.front();
        q.pop();

        if(node->left)
        {
            us[node->left] = node;
            q.push(node->left);
        }
        if(node->right)
        {
            us[node->right] = node;
            q.push(node->right);
        }
    }
}


int  GetMaxTimeToBurnFromTarget(Tree*Root,Tree*Target)
{
    //Check conditions
    if(Root == nullptr || Target == nullptr)
    {
        return 0;
    }

    std::unordered_map<Tree*,Tree*> parent;
    CreateParentPtr(Root,parent);

    std::unordered_set<Tree*> visited;

    std::queue<Tree*>q; //stores the nodes which are at distance k
    q.push(Target); //Start From Target
    visited.insert(Target);
    
    int currLevel = 0;
    int flag = 0;
    while(q.empty() == false)
    {
        int size = q.size();

        flag = 0;


        for(int i = 0; i < size; i++)
        {
          //here we have 3 children
          Tree* curr = q.front();
          q.pop();

          //if node not visited for left
          if(curr->left && visited.find(curr->left) == visited.end())
          {
              q.push(curr->left);
              visited.insert(curr->left);
              flag = 1;
          }
          //same for right
          if(curr->right && visited.find(curr->right) == visited.end())
          {
              q.push(curr->right);
              visited.insert(curr->right);
              flag = 1;
          }
          //now for parent pointer
          if(parent.find(curr) != parent.end() && visited.find(parent[curr]) == visited.end())
          {
              q.push(parent[curr]);
              visited.insert(parent[curr]);
              flag = 1;
          }


        }
        //if(flag)
        currLevel++;
    }

    return currLevel;
}

int MaxTimeRec(Tree*Target,std::unordered_map<Tree*,Tree*> &parent,std::unordered_set<Tree*> &us)
{
    if(Target == nullptr)
    {
        return 0;
    }

    if(us.find(Target) != us.end())
        return 0;

    us.insert(Target);

    int l = MaxTimeRec(Target->left,parent,us);
    int r = MaxTimeRec(Target->right,parent,us);

    int p = 0;

    if(parent.find(Target) != parent.end())
    {
       p = MaxTimeRec(parent[Target],parent,us);
    }

    int val = std::max(l,std::max(r,p));
    return val + 1;


}

Tree *newNode(int val)
{
    return new Tree(val);
}

int main()
{
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->left->left->left = new  Tree(8);
    root->left->right->left = new Tree(9);
    root->left->right->right = new Tree(10);
    root->left->right->left->left = new Tree(11);

    Tree *target = root->left->right->left->left;

    int k = 2;
    
    std::cout << "\n Iterative =";
    std::cout << GetMaxTimeToBurnFromTarget(root,target) << "\n";
    std::cout << "\n Recursive = ";
    std::cout << GetMaxTimeToBurnFromTarget(root,target) << "\n";


    return 0;
}






















