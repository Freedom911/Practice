class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
      
      list<int> l;
      for(int i = 1; i <= m; i++)
      l.push_back(i);
      vector<int>v;
      
      for(int i = 0; i < queries.size(); i++)
      {
        auto iter = l.begin();
        int j = 0;
        while(iter != l.end())
        {
          if(*iter == queries[i])
          {
            v.push_back(j);
            break;
          }
          j++;
          iter++;
        }
        
        if ( iter != l.begin() ) 
        l.splice( l.begin(), l, iter, std::next( iter ) );
    
      }
      
      return v;
        
    }
};
