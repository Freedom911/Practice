class Solution:
    """
     the Logic is not similar to subsequence where we 
     reversed and checked
     Here we take a element and we expand from middle
     both left and right and keep on matching the characters
     eg aba here i is pointing at b. so we match i-1 and i+1
     this is for odd case
     for even we have like abba
     so we match i and i+1 then i-1 and i+2
     """
    def longestPalindrome(self, s: str) -> str:
        start = 0
        maxLen = 1
        n = len(s)

        for i in range(1,n):
            # for Even Case
            l = i-1
            r = i
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 > maxLen:
                    maxLen = r - l + 1
                    start = l
                r += 1
                l -= 1
            
            # for odd
            l = i - 1
            r = i + 1
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 > maxLen:
                    maxLen = r - l + 1
                    start = l
                r += 1
                l -= 1
        
        return s[start:start+maxLen]
        
