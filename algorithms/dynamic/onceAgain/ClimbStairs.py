class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return n
        a = 1 
        b = 1
        c = 0


        for i in range(1,n):
            c = a + b
            a = b 
            b = c
        
        return c


s = Solution()
print(s.climbStairs(2))
print(s.climbStairs(3))
print(s.climbStairs(4))
print(s.climbStairs(5))

