#include <iostream>
#include <queue>
#include <string>

struct TreeNode
{
  TreeNode*Left;
  TreeNode*Right;
  std::string val;
  float prob;

  TreeNode(std::string val)
  {
    this->val = val;
    prob = 0.f;
    Left  = nullptr;
    Right = nullptr;
  }
};

void print(TreeNode *Node)
{
  std::queue<TreeNode*>q;
  q.push(Node);

  while(q.empty() == false)
  {
    TreeNode *n = q.front();
    q.pop();
    int children = 0;
    if(n->Left)
      children++;
    if(n->Right)
      children++;

    float childProb = n->prob/children;

    if(n->Left)
    {
      n->Left->prob = childProb;
      q.push(n->Left);
    }
    if(n->Right)
    {
      n->Right->prob = childProb;
      q.push(n->Right);
    }

    //means a leaf node
    if(n->Left == nullptr && n->Right == nullptr)
      std::cout << "Probability of Node = " << n->val << " = " << n->prob << "\n";
    else
      n->prob = 0.f;



  }
}

int main()
{
  TreeNode*A = new TreeNode("A");
  TreeNode*B = new TreeNode("B");
  TreeNode*C = new TreeNode("C");
  TreeNode*D = new TreeNode("D");
  TreeNode*E = new TreeNode("E");
  TreeNode*F = new TreeNode("F");

  A->prob = 1.f;
  A->Left = B;
  A->Right = C;
  B->Left = D;
  C->Left = E;
  C->Right = F;

  print(A);
}
