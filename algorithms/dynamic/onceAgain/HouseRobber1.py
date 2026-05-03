#House Robber 1 Based on Max Sum in Non Adj
#https://neetcode.io/problems/house-robber/question?list=neetcode150
class Solution:
    #Hypothesis This Function is responible for returning the max by including the index
    # or not including
    def robRec(self, nums: list[int], index: int)->int:
        
        if index == 0:
            return max(nums[index],0)
        
        if index < 0:
            return 0
        
        inc = nums[index] + self.robRec(nums, index - 2)
        dont = 0 + self.robRec(nums,index - 1)

        return max(inc,dont)
    
    def robRecTopDown(self, nums: list[int], index:int, dp: list[int]) -> int:
        
        if index == 0:
            return max(nums[index],0)
        
        if index < 0:
            return 0
        
        if dp[index] != -1:
            return dp[index]
        
        inc = nums[index] + self.robRec(nums, index - 2)
        dont = 0 + self.robRec(nums,index - 1)
        dp[index] = max(inc,dont)

        return dp[index]

    def robRecBottomUp(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]
        
        dp = [-1] * n
        dp[0] = nums[0]
        
        for index in range(1,n):

            inc = nums[index]
            if index > 1:
                inc += dp[index - 2]

            dont = dp[index - 1]
            dp[index] = max(inc,dont)

        return dp[n - 1]
    
    def robRecBottomUpOpti(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]
        
        a = 0 #i-2
        b = nums[0] #previous
        c = 0 # Current
        
        for index in range(1,n):

            inc = nums[index]
            if index > 1:
                inc += a

            dont = b
            c = max(inc,dont)
            a = b
            b = c

        return c
    

    def rob(self, nums: list[int]) -> int:
        #return self.robRec(nums,len(nums) - 1)
        #dp = [-1] * len(nums)
        #return self.robRecTopDown(nums,len(nums) - 1,dp)
        #return self.robRecBottomUp(nums)
        return self.robRecBottomUpOpti(nums)
    


sol = Solution()

print(sol.rob([2,9,8,3,6]))


