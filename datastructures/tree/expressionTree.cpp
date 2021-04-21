//Expression Tree is a tree which has operator at root
// and operand at leaf node only. Need to expand and solve this tree
//https://www.geeksforgeeks.org/expression-tree/
//Will Use a stack and keep pushing elements in postfix order manner
//if operator comes then pop two elements 

#include <iostream>
#include <stack>

struct TreeNode
{
  TreeNode*Left;
  TreeNode*Right;
  std::string val;

  TreeNode(std::string val)
  {
    this->val = val;
    Left  = nullptr;
    Right = nullptr;
  }
};


int add(int a,int b)
{
  return a+b;
}
int sub(int a,int b)
{
  return a - b;
}
int mult(int a,int b)
{
  return a*b;
}

int divison(int a,int b)
{
  if(b == 0)
  {
     std::cerr << "\n Throw by zero error \n";
     return -1;
  }
  return a/b;
}


bool isOperator(const std::string &val)
{
  if(val == "+" || val == "-" || val == "/" || val == "*")
    return true;
  return false;
}

std::string DoOperation(std::string op1,std::string op2,std::string opr)
{
  int (*arrFuncPtr[])(int,int) = {add,sub,mult,divison};

  int a = stoi(op1);
  int b = stoi(op2);

  int ind;
  if(opr == "+")
    ind = 0;
  else if (opr == "-")
    ind = 1;
  else if (opr == "*")
    ind = 2;
  else
    ind = 3;

  return std::to_string((*arrFuncPtr[ind])(b,a));


}

void PostOrderTraversalRec(TreeNode *root)
{
  if(root)
  {
    PostOrderTraversalRec(root->Left);
    PostOrderTraversalRec(root->Right);
    std::cout << root->val << " ";
  }
}


std::string calculate(TreeNode*RootNode)
{

  //we will do postfix traversal
  std::stack<TreeNode*>stack;
  std::stack<std::string>calculate;
  std::string finalVal;
  while(true)
  {
    while(RootNode)
    {
      stack.push(RootNode);
      stack.push(RootNode);
      RootNode = RootNode->Left;
    }

    if(stack.empty())
      break;

    RootNode = stack.top();
    stack.pop();

    //Means we are yet to expllore right sode
    if(!stack.empty() && stack.top() == RootNode)
    {
      RootNode = RootNode->Right;
    }
    else
    {
#if 1

      if(!isOperator(RootNode->val))
      {
        calculate.push(RootNode->val);
      }
      else
      {
        if(calculate.empty())
        {
          return "";
        }
        std::string val = calculate.top();
        calculate.pop();
        if(calculate.empty())
        {
          std::cout << "\n INvlaid Expression Tree \n";
          return "";
        }
        std::string val1 = calculate.top();
        calculate.pop();

        calculate.push(DoOperation(val,val1,RootNode->val));
      }
#endif
     // std::cout << RootNode->val << " ";

      RootNode = NULL; //to avoid parsing this again
    }

  }
  if(calculate.empty())
  {
    std::cout << "\n INvlaid Expression Tree \n";
  }
  else
    finalVal = calculate.top();

  return finalVal;
}



//     +
//   1   *
//      3 -
//       9 1
//ans should be 1 + 3 * (9-1) = 25


int main()
{
  TreeNode*Root = new TreeNode("+");
  TreeNode*Node1 = new TreeNode("1");
  TreeNode*Node2 = new TreeNode("*");
  TreeNode*Node3 = new TreeNode("3");
  TreeNode*Node4 = new TreeNode("-");
  TreeNode*Node5 = new TreeNode("9");
  TreeNode*Node6 = new TreeNode("1");

  Root->Left = Node1;
  Root->Right = Node2;
  Node2->Left = Node3;
  Node2->Right = Node4;
  Node4->Left = Node5;
  Node4->Right = Node6;
  //Node2->Right = Node6; //on uncommenting this it becomes foldable

  std::cout << "\n IS TREE FOLDABLE  == " << calculate(Root) << "\n";
}
