//Given Height of Historgram Need to find Maximum Height we can make
//In this we find NSL and NSR and store the index of them in two array as 
//for a histogram it can go upto NSL and NSR only. Width would be NSR - NSL - 1
//Width of each histogram is 1. Then we loop through the input vector and multiply
//the width and find the max area
//I will be Presenting 3 Solutions
//Solution 1 - Naive Solution
//The main logic is we will be finding the minimum of two bars
//for we start from index 1 and we find the minimum height we can form
//eg 3,2,1. if we start from tower 0 the height is 3 then for 1st tower
//height is 2 so we pick the minimum of these because at last we can form rectablege
//with minimum one only
//so next thing we multiply with the the width
//Solution 2 -
// We gonna Use concept of Nearest Smallest to left and right
//so for each tower we will create two arrays containing nsl and nsr index
//for nsr if there is no nsr we write the index of size. that is the index
//beyond the last tower to allow taking the last tower as well. if we have written -1 then 
//we wont include
//eg 1 2
//for 1 nsr is no one but we can form a histogram of 2 size
//Similarly for NSL we take -1 
//then we calculate the width using nsl - nsr - 1
//then we calculate the area using current[index] * width[index]
//Time Complexity O(n)
//Space Complexity O(4n)
//
//Solution 3 
//It is a one pass solution two find NSR and NSL
//So basically we try to find NSR from left side
//eg 3,7,1
//for 3 NSR is 1 
//we put 3,7 in stack and when 1 comes which is lesser than the top of stack
//we pop 7. so while popping 7's NSR is 1 and 7's NSL is stack top
//so we get both in one pass
//then we just calculate the area with the formula
//area = current tower height * (NSR - NSL - 1)
//Time Complexity - O(n)
//Space Complexity - O(n)


#include <iostream>
#include <stack>
#include <vector>
#include <limits>


//Solution 1 - Naive Solution Using two for loops
//Naive Solution Works LIke this. for each index we try to find min height of the next one
//then we take the max area we can form
int maximumWidthOFHistogramUn(std::vector<int> arr)
{
	if(arr.size() == 0)
	{
		return -1;
	}
	
	//Naive Solution
	int maxArea = -1;
	int size = arr.size();
	for(int i = 0; i < size - 1; i++)
	{
		int prevHeight = arr[i];//Current Height
		for(int j = i + 1; j < size; j++)
		{
			prevHeight = std::min(prevHeight,arr[j]);//Minimum of height from this tower
			maxArea = std::max(maxArea,prevHeight * (j- i + 1)); //j-i + 1 represents width
		}
	}
	
	return maxArea;
}

std::vector<int> getNSL(std::vector<int> in)
{
  //Find the next smallest element and return the index vector
  std::vector<int> nslIndex;
  //This stores the index of NSL
  std::stack<std::pair<int,int>>s;
  for(int i = 0; i < in.size(); i++)
  {
    while(s.empty() == false && s.top().first > in[i])
    {
      s.pop();
    }

    if(s.empty())
      nslIndex.push_back(-1);
    else
      nslIndex.push_back(s.top().second); 

    s.push(std::make_pair(in[i],i));
  }

  return nslIndex;
}

std::vector<int> getNSR(std::vector<int> in)
{
  std::vector<int> nsrIndex(in.size(),0);
  std::stack<std::pair<int,int>>s;

  for(int i= in.size() - 1; i>= 0; i--)
  {
    while(s.empty() == false && s.top().first > in[i])
    {
      s.pop();
    }
    if(s.empty())
    {
      //we are assuming the nth element that is beyond the total has minimum value
      //so pushing nth
      nsrIndex[i] = (in.size());
    }
    else
    {
      nsrIndex[i] = (s.top().second);
    }

    s.push(std::make_pair(in[i],i));
  }

  return nsrIndex;
}

//Solution 2 - Using NSL and NSR index array 
int maximumWidthOFHistogram(std::vector<int> in)
{
  std::vector<int> width;
  std::vector<int> nsr = getNSR(in);
  std::vector<int> nsl = getNSL(in);


  for(int i = 0; i < nsr.size(); i++)
  {
    width.push_back(nsr[i] - nsl[i] - 1); //1 is due to width of each bar
  }

  int max = std::numeric_limits<int>::min();
  //in contains input and it is the length of each bar so basically height
  for(int j = 0; j < in.size(); j++)
  {
    max = std::max(max,in[j] * width[j]); //set max which has max area l * b
  }


  return max;


  
}

//Super Optimized Solution 
//while tring to find NSR and NSL in one loop
int SuperOptimized(std::vector<int> in)
{
    //1st we Try to find NSR.
    //then as soon as we get the NSR we pop the elements from the stack and for them
    //the nsr is the current element and nsl is the stack top

  std::stack<std::pair<int,int>> st;
  int maxArea = -1;
  for(int i = 0; i < in.size(); i++)
  {
	  //finding NSR
	  while(st.empty() == false && st.top().second >= in[i])
	  {
		  //Current Tower Height
		  int elem = st.top().second;
		  int index = st.top().first;
		  st.pop();
		  
          //NSR
		  int next = i;
          //NSL
		  int prev = st.empty() == false ? st.top().first : -1;
		  
		  maxArea = std::max(maxArea,elem * (next - prev - 1));
		  
	  }
	  st.push({i,in[i]});
  }
  
  //remaining
  //it may happen that the stack is not empty
  //eg 1,2,3
   while(st.empty() == false)
	  {
		  
		  int elem = st.top().second;
		  int index = st.top().first;
		  st.pop();
		  
		  int next = in.size();
		  int prev = st.empty() == false ? st.top().first : -1;
		  
		  maxArea = std::max(maxArea,elem * (next - prev - 1));
		  
	  }
  
  return maxArea;

}

int main()
{
  std::cout << "\n MAXIMUM AREA = " << maximumWidthOFHistogram({6,2,5,4,5,1,6});
  std::cout << "\n MAXIMUM AREA = " << maximumWidthOFHistogramUn({6,2,5,4,5,1,6});
  std::cout << "\n MAXIMUM AREA = " << SuperOptimized({6,2,5,4,5,1,6});

}

