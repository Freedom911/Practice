/**
 * https://leetcode.com/problems/combination-sum/
 */ 
class Solution {
public:

    void solve(vector<int>& candidates, int target,vector<vector<int>> &res,
    vector<int> &temp,int j)
    {
        if(j < 0)
        {
            if(target == 0)
            res.push_back(temp);
            return;
        }

        //two choices
        if(candidates[j] <= target)
        {
            temp.push_back(candidates[j]);
            solve(candidates,target - candidates[j],res,temp,j);
            temp.pop_back();
            solve(candidates,target,res,temp,j - 1);
        }
        else
        {
            solve(candidates,target,res,temp,j - 1);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = candidates.size();
        solve(candidates,target,res,temp,n - 1);
        return res;
    }
};
