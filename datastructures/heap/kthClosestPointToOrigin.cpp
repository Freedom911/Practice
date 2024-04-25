class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
	
		std::vector<std::vector<int>> v(k,std::vector<int>(2,-1));
		std::priority_queue<std::pair<int,std::pair<int,int>>> pr;
		
		for(int i = 0; i < points.size(); i++)//no of rows
		{
			int distance = (points[i][0] * points[i][0]) + (points[i][1]*points[i][1]);
			pr.push(std::make_pair(distance,std::make_pair(points[i][0],points[i][1])));
			
			if(pr.size() > k)
			{
				pr.pop();
			}
		}
		int i = 0;
		while(pr.empty() == false)
		{
			v[i][0] = pr.top().second.first;
			v[i][1] = pr.top().second.second;
			i++;
			pr.pop();
			
		}
		
		return v;
        
    }
};