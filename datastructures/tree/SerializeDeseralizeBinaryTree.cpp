/**
 *
 *  Given a Tree . 1st Serialize to a string and then get the original tree back
 *
 *  Approach 1 we could use the approach defined in creating binary tree from pre and ino
 *  first create a string 10,20,30 for inorder
 *  append pre order 20,10,30 so final string will begin
 *  10,20,30 20,10,30 . now while desierizling we first split into two inorder and pre order
 *  and we create unique tree. Drawback is we cant handle duplicate elements
 *
 *  Approach 2 we use only level order for serializing and desierizlign
 *         10
 *       20   3
 *           4
 * so we use level order traversal and if child node is not present we append $
 * so we get 10,20,3,#,#,4,#,#,#
 * first 2 hashes of 20 then next hash of 3 right side and finally two hashes of 4
 *
 * After serializing we again use level order traversal
 * so we put 10 in queue and create root node
 * then we take next one element and append to left and take next element and append to right
 * and we continue like that to create a tree. element is popped out when child are explored
 */
 #include <iostream>
 #include <string>
 #include <queue>
 #include <sstream>
 
 
 struct Tree
 {
	 int data;
	 Tree*left;
	 Tree*right;
	 
	 Tree(int d):data(d),left(nullptr),right(nullptr){}
 };
 
 
 std::string Serialize(Tree*Root)
 {
	 if(Root == nullptr)
	 {
		 return "";
	 }
	 //Using Level order traversal for creating string
	 std::string serialzedString;
	 std::queue<Tree*>q;
	 q.push(Root);
	 while(q.empty() == false)
	 {
		 Tree*Node = q.front();
		 q.pop();
		 
		 if(Node != nullptr)
		 {
			 serialzedString += std::to_string(Node->data) + ",";
			 q.push(Node->left);
			 q.push(Node->right);
		 }
		 else
			 serialzedString += "#,";
		 
	 }
	 
	 return serialzedString;
 }
 
 
 Tree* DeSerialize(const std::string &serialzedString)
 {
	 if(serialzedString.empty() || serialzedString[0] == '#')
	 {
		 return nullptr;
	 }
	 //we again use level order traveral for the same
	 std::queue<Tree*>q;
	 std::stringstream ss(serialzedString);
	 
	 //with this we get element with , delimiter so eg if 10,20,30
	 //then on first call we get 10 then on second we get 20 and so on
	 std::string buff;
	 std::getline(ss,buff,',');
	 
	 //1st step we create root and push in queue
	 Tree*Root = new Tree(stoi(buff));
	 q.push(Root);
	 
	 while(q.empty() == false)
	 {
		 Tree* Node = q.front();
		 q.pop();
		 
		 //get left child 
		 std::getline(ss,buff,',');
		 if(buff != "#")
		 {
			 //means not null 
			 Node->left = new Tree(stoi(buff));
			 q.push(Node->left);
		 }
		 
		 //get right child 
		 std::getline(ss,buff,',');
		 
		 //if value not null 
		 if(buff != "#")
		 {
			 //means not null 
			 Node->right = new Tree(stoi(buff));
			 q.push(Node->right);
		 }
		 
	 }
	 return Root;
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
	Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->right->left = new Tree(4);
    root->right->right = new Tree(5);
	
	std::cout << "\n Initial Tree before Serializing \n";
	printInorder(root);
	
	std::string serialzedString = Serialize(root);
	std::cout << "\n After Serializing = " << serialzedString << "\n";
	
	Tree* DeserializedRoot = DeSerialize(serialzedString);
	
	std::cout << "\n After Deserializing Tree \n";
	printInorder(DeserializedRoot);
 }