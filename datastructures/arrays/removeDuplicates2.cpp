#include <iostream>
#include <vector>
using namespace std;

 int removeDuplicates1(vector<int>& nums)
 {
	 std::vector<int> nums2;
	 for(int i = 0; i < nums.size(); i++)
	 {
		 if(i == 0 || i == 1 || nums[i] != nums[i-2])
		 {
			 nums2.push_back(nums[i]);
		 }
	 }
	 nums = nums2;
	 return nums2.size();
 }

	//Concetp is that if we start with a new array then we use k variable which is a pointer to_char_type
	//new array and k is updated if in orriginal array the element at current index is different than
	//previous two elements then we insert in new array and update k-2
	//now same thing can be used when we dont want to use new array
	//we compare array at current index with array at previous two element using k since k is the pointer
	//which basically telling the valid index in the non duplicated array and not i 
	//eg 1,1,1,2,2,3 if we use i-2 then the result will be wrong. because in middle the array is
	//1,1,2,2,2,3 now i = 4,k = 3 now if we had used i -2 then ar[4] != ar[2] which is 2 != 2 which is false
	//and then we do for last element ar[5] != ar[3] 3 != 2 which is true then ar[k] = ar[i] k was 3
	//so the array would become 1,1,2,3,2,3 which is wrong . as you can see we didnt wanted ar[4] comparision with ar[2] as we
	//wanted comparision with ar[1]. this happened because we didnt ignore the element 2 we duplicated ourself. as you can see in the
	//array there are 3 2s which was not there.
    int removeDuplicates(vector<int>& nums) 
	{
		int k = 0;
		int maxAllowed = 2;
		for(int i = 0; i < nums.size(); i++)
		{
			if(i < maxAllowed || nums[i] != nums[k-maxAllowed])
			{
				nums[k] = nums[i];
				k++;
			}
		}
		return k;
	 	
    }

int main()
{
  std::vector<int> v{1,1,1,2,2,2,2,3};
  //std::vector<int> v{0,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,3,3,4,4,5,5,5,5,5,5};
  std::cout << removeDuplicates(v) << "\n";
  std::cout << "\n";
  for(int i = 0 ; i < v.size(); i++)
  {
	  std::cout << v[i] << ",";
  }
}