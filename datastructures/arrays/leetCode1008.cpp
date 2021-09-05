#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

  public:



    TreeNode *build(vector<int> &pre,int l,int r)

    {

      if(l > r)
        return nullptr;


      TreeNode *Root = new TreeNode(pre[l]);

      if(l == r)
        return Root;

      int k = l+1;
      while(k <= r) {
        if(pre[k] > pre[l]) {
          break;
        }
        k++;
      }

      Root->left = build(pre,l+1,k-1);

      Root->right = build(pre,k,r);



      return Root;





    }



    TreeNode* bstFromPreorder(vector<int>& preorder) {

      if(preorder.size() == 0) {
        return NULL;
      }

      return build(preorder,0,preorder.size() - 1);



    }


    int main()
    {
      Solution s;
      vector<int>v{8,5,1,7,10,12};
      s.bstFromPreorder(v);
    }
