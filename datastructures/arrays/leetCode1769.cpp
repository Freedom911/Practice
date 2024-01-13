class Solution {
public:
    vector<int> minOperations(string boxes) 
	{
        //using cumulative sum from left side plus right side
		int n = boxes.size();
		std::vector<int> ans(n,0);
		
		int leftcf = 0, count = 0;
		for(int i = 0; i < n; i++)
		{
			ans[i] = leftcf;
			
			if(boxes[i] == '1')
			{
				count ++;
			}
			leftcf += count;
		}
		
		int rightcf = 0;
		count = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			ans[i] += rightcf;
			
			if(boxes[i] == '1')
			{
				count++;
			}
			rightcf += count;
		}
		
		
		return ans;
		
    }
	
	vector<int> minOperationsN2(string boxes) 
	{
	  std::vector<int> ans(boxes.size(),0);
	  
	  for(int i = 0; i < boxes.size(); i++)
	  {
		for(int j = 0; j < boxes.size(); j++)
		{
		  if(i == j)
		  {
		    continue;
		  }
		  if(boxes[j] == '1')
		  {
		    ans[i] += std::abs(j - i);
		  }
		}
	  }
	  
	  return ans;
        
    }
};
