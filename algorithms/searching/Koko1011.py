class Solution:
    def isPossible(self, piles: List[int], bananaSpeed: int, guardHr: int) -> bool:
        s = sum(math.ceil(x/bananaSpeed) for x in piles)
        return s <= guardHr
    
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        n = len(piles)
        r = max(piles)
        res = -1

        while l <= r:
            mid = l + (r-l)//2
            if self.isPossible(piles,mid,h):
                res = mid
                r = mid - 1
            else:
                l = mid + 1

        return res
        
