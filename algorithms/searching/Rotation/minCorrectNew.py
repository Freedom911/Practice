class Solution:
    def findMin(self, nums: list[int]) -> int:
        n = len(nums)
        if n== 0:
            return -1
        elif n == 1:
            return nums[0]
        elif nums[0] < nums[n-1]:
            return nums[0]
        elif nums[-1] < nums[-2]:
            return nums[-1]
        
        l = 1
        r = len(nums) - 2

        while l <= r:
            mid = (l+r)//2
            prev = mid - 1
            next = mid + 1

            if nums[mid] < nums[prev] and nums[mid] < nums[next]:
                return nums[mid]
            
            if nums[mid] > nums[l] and nums[r] > nums[mid]:
                return nums[l]
            
            #if already sorted then return
                        
            if nums[l] <= nums[mid]: #this is sorted
                l = mid + 1
            else:
                r = mid - 1
        
        return -1

