
/**
 *  First Solution we can extend with Combination Sum and use sorting but
 *  it will be expensive. in this approach we are basically prune the branches
 * we wont even explore. 
 * so if on a level we say if we have already selected the element we wont explore as it is already included. for that we need to ensure the initial
 * elements are sorted
 */

class Solution {
public:

    void solve(vector<int>& candidates, int target,vector<vector<int>> &res,
    vector<int> &temp,int j)
    {
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }

        //for we start the choices
        for(int i = j; i < candidates.size(); i++)
        {
            //Check if same element then ignore
            if(i > j && candidates[i] == candidates[i-1])
            {
                continue;//dont include
            }
            //also if 
            if(candidates[i] > target)
            {
                break; //because age wale will be greater
            }
                temp.push_back(candidates[i]);
                 solve(candidates,target - candidates[i],res,temp,i+1);
                 temp.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> vec;
        vector<int> temp;
        int n = candidates.size();
        solve(candidates,target,vec,temp,0);



        return vec;
    }
};
