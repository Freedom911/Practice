/**
 *  Convert a tree to link list in pre order format 
 * we simply use morris pre order traversal
 *
 */

#include <iostream>
#include <stack>
struct Tree
{
	int data;
	Tree* left;
	Tree *right;
	Tree(int d):data(d),left(nullptr),right(nullptr){}
};

struct LinkedList
{
	int data;
	LinkedList *next;
	LinkedList(int d): data(d),next(nullptr){}
};

LinkedList* flatten(Tree*Root)
{
	std::stack<Tree*>st;
	LinkedList * head = nullptr;
	LinkedList * head1 = nullptr;
	while(true)
	{
		while(Root)
		{
			//std::cout << Root->data << ",";
			LinkedList * l = new LinkedList(Root->data);
			if(head == nullptr)
			{
				head1 = l;
				head = head1;
			}
			else
			{
				head->next = l;
				head = l;
			}
			st.push(Root);
			Root = Root->left;
		}
		
		if(st.empty())
		{
			return head1;
		}
		
		Root = st.top();
		st.pop();
		Root = Root->right;
	}
	return nullptr;
}

void printPreorder(Tree*Root)
{
	if(Root)
	{

		std::cout << Root->data << ",";
		printPreorder(Root->left);

		printPreorder(Root->right);
	}
}


int main()
{
	Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->left->right->right = new Tree(6);
    root->right->right = new Tree(7);
    root->right->left = new Tree(8);

    LinkedList* l =flatten(root);
	
	std::cout << "\n PRE = ";
	printPreorder(root);
	std::cout << "\n LL \n";
	while(l != nullptr)
	{
		std::cout << l->data << ",";
		l = l->next;
	}
	
}