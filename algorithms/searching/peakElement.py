class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l = 0
        s = len(nums)
        r = s - 1
        if len(nums) == 1:
            return 0

        while l <= r:
            mid = l + (r-l)//2

            if mid + 1 < s and mid - 1>= 0:
                if nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]:
                    return mid
                elif nums[mid+1] > nums[mid]:
                    l = mid + 1
                else:
                    r = mid - 1
            elif mid + 1 < s:
                if nums[mid] > nums[mid + 1]:
                    return mid
                elif nums[mid] < nums[mid+1]:
                    return mid + 1
                else:
                    return -1
            elif mid - 1 >= 0:
                if nums[mid] > nums[mid - 1]:
                    return mid
                elif nums[mid-1] > nums[mid]:
                    return mid - 1
                else:
                    return -1

        return -1
