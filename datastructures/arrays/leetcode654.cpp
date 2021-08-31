/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      
      if(nums.size() == 0)
      {
        return nullptr;
      }
      
      int maxElement = 0;
      int i = 0;
      for(int j = 0; j < nums.size(); j++)
      {
        if(nums[j] > maxElement)
        {
          maxElement = nums[j];
          i = j;
        }
      }
      
      std::vector<int> v1(nums.begin(), nums.begin() + i);
      std::vector<int> v2(nums.begin() + i + 1, nums.end());
      TreeNode *left = constructMaximumBinaryTree(v1);
      TreeNode *right = constructMaximumBinaryTree(v2);
      
      return new TreeNode(maxElement,left,right);
        
    }
};
