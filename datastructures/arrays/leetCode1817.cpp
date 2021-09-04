class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
      
      vector<int> res(k,0);
      map<int,set<int>> um;
      for (auto &l : logs)
      {
        {
          um[l[0]].insert(l[1]);
        }
      }
            for(auto &i : um){
            res[i.second.size()-1]++;
        }
      
      return res;
      
    }
};
