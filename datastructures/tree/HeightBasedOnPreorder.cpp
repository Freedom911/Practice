/**
  Get Height Based on Pre order string given like his nlnll
  where n is the internal node and l is the leaf node
  internal node is a node which is having a child
  root is a internal node if it has children
  
  Here the tree is full Binary tree i.e every node is having
  0 or 2 children
  
  So in string nlnll n is root according to pre order since pre order is 
  Root Left Right. Moreover Left node is l and right node is n
  
  Base conditions would be if index or counter > str.length we return 0
  or if str[index] == 'l' means it is a leaf node and the height is 0
  0 representing height at last node
  
  to get to left node we do index++ and to get right node we again increment 
  index++ . so if index = 0 we get left node and index = 1 and right node and index 2
  
  with that we start coding 
  
  Another Way is to just use formula
  (n-1)/2 where n represents total nodes
  can derive this
  3 nodes - 1 depth
  5 nodes - 2 depth
  7 nodes - 3 depth
  Merci
*/


#include <iostream>
#include <string>


int getHeightFormula(const std::string &tree)
{
	return (tree.length() - 1)/2;
}


//Hypothesis - This function returns height of tree at given index
int getHeight(const std::string &tree,int &index)
{
	//Base COnditions
  if(index >= tree.length() || tree[index] == 'l')
  {
	  return 0;//Height 0 in this case
  }

	//induction step
	//to0 get to left node we increment index
	index++;
	int l = getHeight(tree,index);
	
	//again increment fo rrught index
	index++;
	int r = getHeight(tree,index);
	
	//now pick the max and add 1
	return std::max(l,r) +1;
}

int main()
{
	std::string str = "nlnll";
	int index = 0;
	
	std::cout << "\n Height of = " << str << " " <<  getHeight(str,index) << "\n";
	std::cout << "\n Formula Height of = " << str << " " <<  getHeightFormula(str) << "\n";
	
	str = "nlnnlll";
	index = 0;
	std::cout << "\n Height of = " << str << " " << getHeight(str,index) << "\n";
	std::cout << "\n Formula Height of = " << str << " " <<  getHeightFormula(str) << "\n";
}