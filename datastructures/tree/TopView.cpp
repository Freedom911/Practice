/**
 In Top View order traversal we print nodes coming in straiht line
 eg 
           1
        2     3
      4  5   6 7
	  
	  Op - 4 2 1 3 7
	  
	  THe Concept is just like vertical order
	  where we have coordinate system. The differce here is we 
	  will only print the first element on the line
	  
	  DS - Map[x,node val]
	  queue<Node,int X>
	  
	  THe concept is simple we will only insert the first element of the line
	  by checking the map

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

void PrintTopView(BinaryTree *Root)
{
	if(Root == nullptr)
	{
		return;
	}
    std::map<int,int> mapper;
    std::queue<std::pair<BinaryTree*,int>> q;
	q.push({Root,0});

    while(q.empty() == false)
    {
        auto elem = q.front();
        BinaryTree* temp = elem.first;
        int x = elem.second;
        q.pop();

		if(mapper.find(x) == mapper.end())
		{
			mapper[x] = temp->data;
		}
       

        if(temp->left)
        {
            q.push({temp->left,x-1});
        }
        if(temp->right)
        {
            q.push({temp->right,x+1});
        }
    }




  //traverse mapper
    for(auto p:mapper)
    {
       std::cout << p.second << ",";
        
    }


}


int main()
{

    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);

    PrintTopView(root); 

}
