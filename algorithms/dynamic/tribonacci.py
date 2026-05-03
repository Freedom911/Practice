class Solution:
    def tribonacci(self, n: int) -> int:
        #Tn+3 = Tn + Tn+1 + Tn+2
        if n <= 1:
            return n
        elif n == 2:
            return 2
        
        a = 0
        b = 1
        c = 1
        d = 0

        for i in range(3,n+1):
            d = a + b + c
            a = b
            b = c
            c = d
        return c
    

s = Solution()
print(s.tribonacci(3))
print(s.tribonacci(21))