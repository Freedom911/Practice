class Solution:
    def checkIsPossible(self,stations,total_stations_allowed,maxDist)->bool:
        total_stations_req = 0
        for i in range(0,len(stations) - 1):
            total_stations_req += math.ceil(abs(stations[i+1]-stations[i])/maxDist) - 1

        return total_stations_req <= total_stations_allowed

        
    def findSmallestMaxDist(self, stations, K):
        # Code here
        l = 0
        n = len(stations)
        r = stations[n-1]
        res = -1
        steps = 0.000001

        while r-l > 1e-6:
            mid = l + (r-l)/2

            if self.checkIsPossible(stations,K,mid):
                res = mid
                r = mid - steps
            else:
                l = mid + steps

        return res
