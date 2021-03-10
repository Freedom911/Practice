// { Driver Code Starts
//Initial Template for C++


//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> inOrder(Node* node);

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



vector<int> preOrder(Node* root);

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        
        getline(cin, s);
       
        Node* root = newNode(1); //buildTree(s);

        Node *head = root;


	Node *two = newNode(2);
	Node *three = newNode(3);
	Node *four = newNode(4);
	Node *five = newNode(5);
	
	root->left = two;
	root->right = three;

	two->left = four;
	two->right = five;


	four->left = NULL;
	four->right = NULL;
	
	five->left = NULL;
	five->right = NULL;
	
	three->left = NULL;
	three->right = NULL;




        vector<int> ans;
        ans = preOrder(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";

        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/

vector<int> preOrder(Node* root)
{
    vector<int> elem;
    if(root == NULL)
    return elem;
    //code here
    stack<Node*> nodes;
    
    
      elem.push_back(root->data);    
    nodes.push(root);
    
    while(!nodes.empty() && root)
    {
        Node *right = root->right;
        root = root->left;
        
        if(root != NULL)
        {
            elem.push_back(root->data);    
            nodes.push(root);
        }
        else
        {
            
           // root = root->right;
            if(right == NULL)
            {
                if(!nodes.empty())
                {
                    root = nodes.top();
                    nodes.pop();
                }

                while( !nodes.empty())
                {
                    std::cout << "\n WOOT DATA = " << root->data << "\n";
                    root = nodes.top();
                    if(root && root->left == NULL && root->right == NULL)
                    {
                        std::cout << "\n ROOT DATA = " << root->data << "\n";
                        nodes.pop();
                        
                    }
                    else if(root && root->right != NULL)
                    {
                        nodes.pop();
                        root = root->right;
                        elem.push_back(root->data);
                        nodes.push(root);
                        break;
                    }

                    else
                    {
                        break;
                    }
                    

                }
            }
            else
            {
                elem.push_back(right->data);
            }
        }
    
    }
    return elem;
    
}
