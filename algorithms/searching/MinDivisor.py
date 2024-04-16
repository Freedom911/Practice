class Solution:
    def isPossible(self, nums: List[int], divisor: int, threshold: int) -> bool:
        s = sum(math.ceil(x/divisor) for x in nums)
        #for x in nums:
        #    s = s + math.ceil(x/divisor)
        return s <= threshold
            
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        l = 1
        r = max(nums)
        res = -1
        while l <= r:
            mid = l + (r-l)//2

            if self.isPossible(nums,mid,threshold):
                r = mid - 1
                res = mid
            else:
                l = mid + 1

        return res
