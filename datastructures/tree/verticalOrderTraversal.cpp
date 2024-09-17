/**
 In vertical order traversal we print nodes coming in straiht line
 eg 
           1
        2     3
      4  5   6 7

      We will first print 4 then 2 then 1,5,6 then 3 ,7
      4
      2
      1,5,6
      3
      7
      Note for 1,5,6 line we print in ascending order for 5,6 


      So we define a coordinate system were root node is at (0,0)
      2 is at(-1,1) and 3 is at (1,1)
      so when we move left we decrement x and increment y when we go down
      similarly when move right we increment x and increment y

      we define a datastructure map<int,map<int,multiset>> were first key is x coordinate
      second key is y then in multiset we have multiple nodes like for 5 and 6 we have x and y
      coordinate(0,2) so we have a multiset which automatically sorts and we use multiset to sort

      Output is vector<vector<int>>
      vector[0] will have 4
      vector[1] will have 2
      vector[2] will have vector of 1,5,6
      vector[3] will have 3
      vector[4] will have 7
*/


#include <iostream>
#include <queue>
#include <map>
#include <set>

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

void PrintVertical(BinaryTree *Root)
{
    std::map<int,std::map<int,std::multiset<int>>> mapper;
    std::queue<std::pair<BinaryTree*,std::pair<int,int>>> q;

    q.push({Root,{0,0}});

    while(q.empty() == false)
    {
        auto pair = q.front();
        BinaryTree* node = pair.first;
        int x = pair.second.first,y = pair.second.second;
        q.pop();

        mapper[x][y].insert(node->data);

        if(node->left)
        {
            q.push({node->left,{x-1,y+1}});
        }
        if(node->right)
        {
            q.push({node->right,{x+1,y+1}});
        }
    }


    //finally Store result
    std::vector<std::vector<int>>ans;

  //traverse mapper
    for(auto p:mapper)
    {
        std::vector<int> cols;
        //traverse second map
        for(auto a:p.second)
        {
            //store for multiset
            cols.insert(cols.end(),a.second.begin(),a.second.end());
        }
        ans.push_back(cols);
        
    }

    for(int i = 0; i < ans.size(); i++)
    {
        std::cout << "" << i+1 << ") ";
        for(int j = 0;j < ans[i].size(); j++)
        {
            std::cout << ans[i][j] << ",";
        }
        std::cout << "\n";
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
    root->right->left->right = new BinaryTree(8);
    root->right->right->right = new BinaryTree(9);
    PrintVertical(root); 

}

