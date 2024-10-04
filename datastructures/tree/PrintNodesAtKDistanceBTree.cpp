/**
 * Statement - Given a binary tree.
 *
 * We need to find nodes which are at distance k from a target node. Now the twist here is
 * the nodes can be at right side left side or even up side
 *
 * eg 
 *
 *           1
 *         2   3
 *            4 6
 *           5
 * Given Target = 2
 * k = 3
 * we need to find nodes which are at distance 3 from target node 2
 * here we will have 4,6
 *
 * Hmm good
 *
 * The solution here is simple
 * we are basically having problem with going upwards. if we only had to go left or right
 * then we would have used level order traversal till kth level and printed the nodes.
 *
 * So we create a function that basically like curr node to parent node. we use level order traversal for that
 * and we use hash map to store the parent pointer of the current node.
 *
 * Then after getting the parent pointer we basically do level order traversal till like k
 *
 * and instead of two children here we have three left,right,upwards. to avoid infinite loop we use visited data
 * structure.
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

//Print nodes at kth distance
void  PrintNodesAtKDist(Tree*Root,Tree*Target,int k)
{
    //Check conditions
    if(Root == nullptr || Target == nullptr)
    {
        return;
    }

    std::unordered_map<Tree*,Tree*> parent;
    CreateParentPtr(Root,parent);

    std::unordered_set<Tree*> visited;

    std::queue<Tree*>q; //stores the nodes which are at distance k
    q.push(Target); //Start From Target
    visited.insert(Target);
    
    int currLevel = 0;
    while(q.empty() == false)
    {
        int size = q.size();

        //Check if we at destiny
        //because destiny arrives all the same
        if(currLevel == k)
        {
            break;
        }



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
          }
          //same for right
          if(curr->right && visited.find(curr->right) == visited.end())
          {
              q.push(curr->right);
              visited.insert(curr->right);
          }
          //now for parent pointer
          if(parent.find(curr) != parent.end() && visited.find(parent[curr]) == visited.end())
          {
              q.push(parent[curr]);
              visited.insert(parent[curr]);
          }


        }
        currLevel++;
    }

    std::cout << "\n Nodes at distance " << k << " = ";
    while(q.empty() == false)
    {
        std::cout << q.front()->data << ",";
        q.pop();
    }

}

Tree *newNode(int val)
{
    return new Tree(val);
}

int main()
{
    Tree* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    Tree* target = root->left->right;

    int k = 2;

    PrintNodesAtKDist(root,target,k);


    return 0;
}






















