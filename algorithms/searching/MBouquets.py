class Solution:
    def IsPossible(self, bloomDay: List[int],desBouq: int,flowers: int,maxDays: int)->bool:

        cntFlowers = 0
        cntBouquets = 0
        # we keep increasing flower count till the bloom day is greater than
        # max days then we reset the counter
        # also number of bouquets will be equal
        # to total flowers/no of flowers required in a bouqet
        for i in range(0,len(bloomDay)):
            if bloomDay[i] <= maxDays:
                cntFlowers +=1
            else:
                cntBouquets += cntFlowers//flowers
                cntFlowers = 0

        cntBouquets += cntFlowers // flowers
        return cntBouquets >= desBouq # means we can form bouqets
    
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:

        totalFlowers = m * k
        # not possible as we dont have enough flowers
        if totalFlowers > len(bloomDay):
            return -1

        l = min(bloomDay)
        r = max(bloomDay)
        res = -1

        while l<= r:
            mid = l + (r-l)//2

            # keep looking for minimum
            if self.IsPossible(bloomDay,m,k,mid):
                r = mid - 1
                res = mid

            else:
                l = mid + 1

        return res
