/**
 Given a node we need to find the path from the root
 Previous Knowledge we use pre order traversal concept.
 We maintain an array containing the path. we push when we go towards the target node
 if we cant find the target node we pop.
 Basically this is a question of backtracking
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

//Hypothesis - This Function Prints Root to node and returns true if path found
//false otherwise. Maintains path in ans
bool PrintRootToNode(BinaryTree *Root,std::vector<int> & ans,const int &val)
{
	//Base conditions
	//1 if root is null then we didnt find the path so we return null
	if(Root == nullptr)
	{
		return false;
	}
    
	//Push Path in vector
	ans.push_back(Root->data);
	
	//if Elem found we return the path
	if(Root->data == val)
	{
		return true;
	}


	//Induction Step
    //if found anywhere we return the ans containing path and return true
	if(PrintRootToNode(Root->left,ans,val) ||
	   PrintRootToNode(Root->right,ans,val))
	   {
		   return true;
	   }
	   
	//otherwise we pop it
	ans.pop_back();
	
	return false; // oh oh we didnt find the element
	
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



    int targetLeafValue = 7;
	std::vector<int> ans;
    PrintRootToNode(root,ans,targetLeafValue); 
	
	for(int i = 0; i < ans.size(); i++)
	{
		std::cout << ans[i];
		
		if(i+ 1 != ans.size())
		{
			std::cout << "->";
		}
		else
		{
			std::cout << "\n";
		}
	}

}