#User function Template for python3

class Solution:
    def IsPossible(self, arr, n, maxPainter, maxPaint):
        cntPainter = 1
        s = arr[0]
        for i in range(1,len(arr)):
            s += arr[i]
            if s > maxPaint:
                s = arr[i]
                cntPainter += 1

        return cntPainter <= maxPainter
    
    def minTime (self, arr, n, k):
        #code here
        if k > n:
            return -1
        if k == n:
            return max(arr)
        l = max(arr)
        s = sum(arr)
        r = s - min(arr)
        res = -1

        while l <= r:
            mid = l + (r-l)//2
            if self.IsPossible(arr,n,k,mid):
                res = mid
                r = mid - 1
            else:
                l = mid + 1

        return res
        

