/**
 *
 *  Create Binary Tree From Inorder and Post order. Remember if we have inorder 
 * then we can create a unique tree but only if pre and post ordder is given then we cant
 * Here the elements are also unique.
 * Ex [10,20,30] is Inorder and Post order [20,10,30] then
 * first we take last element from post order this will be the root
 * we find the index of 30 in inorder and we can get left and right tree as inorder is left root right
 * then we recursively solve left and right
 * to find index we use unordered map to searching faster
 * 
 *
 */
 #include <iostream>
 #include <vector>
 #include <unordered_map>
 
 
 struct Tree
 {
	 int data;
	 Tree*left;
	 Tree*right;
	 
	 Tree(int d):data(d),left(nullptr),right(nullptr){}
 };
 
 //Hypothesis - This function create tree for given inorder and Post order between start and end
 Tree *helper(const std::vector<int>&in,const std::vector<int>&post,
			  int iStart,int iEnd,int pStart,int pEnd,std::unordered_map<int,int> &us)
			  {
				  //Base conditions
				  if(iStart > iEnd || pStart > pEnd)
				  {
					  return nullptr;
				  }
				  
				  //Create Root node here difference is we pick the last
				  Tree*Root = new Tree(post[pEnd]);
				  
				  //index of element in inorder
				  int index = us[Root->data];
				  
				  int nums = index - iStart;
				  
				  //Building left and right subtree
				  //in post order include element next to pstart since pstart is already root
				  //and we need top have index till nums - 1
				  Root->left = helper(in,post,iStart,index - 1,pStart,pStart + nums - 1,us);
				  Root->right = helper(in,post,index + 1,iEnd,pStart + nums,pEnd - 1,us);
				  
				  return Root;
			  }
 
 Tree * build(const std::vector<int>&in,const std::vector<int>&post)
 {
	 //Conditions check
	 if(in.size() == 0 || post.size() == 0 || in.size() != post.size())
	 {
		 return nullptr;
	 }
	 
	 int size = post.size();
	 std::unordered_map<int,int> us;
	 //map containing index of inorder for fster search
	 for(int i = 0; i < in.size(); i++)
	 {
		 us[in[i]] = i;
	 }
	 
	 return helper(in,post,0,size - 1,0,size - 1, us);
 }
 
 void printInorder(Tree*Root)
 {
	 if(Root == nullptr)
	 {
		 return;
	 }
	 
	 printInorder(Root->left);
	 std::cout << Root->data << ",";
	 printInorder(Root->right);
 }
 
 
 int main()
 {
	
    std::vector<int> inorder = {40, 20, 50, 10, 60, 30};
    std::vector<int> postorder = {40, 50, 20, 60, 30, 10};
    Tree * Root = build(inorder,postorder);
	
	std::cout << "\n After Building Inorder traversal is  \n";
	printInorder(Root);
	
 }
 
 