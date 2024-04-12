#This is related to Binary Search on answer or Minimize Max Pages allocated to student

def CanPlaceCow(stalls: list[int], maxDist: int, cows: int)->bool:
    n = len(stalls)
    lastPlacedCow = stalls[0]
    cntCows = 1
    print(maxDist)

    for i in range(1,n):
        nextCow = stalls[i]

        if nextCow - lastPlacedCow >= maxDist: # means both cow are more than max distance appart then we can place
            cntCows = cntCows + 1
            lastPlacedCow = nextCow
            # This means that our farm can accomodate cows speciefied it can accomodate even more
            if cntCows >= cows:
                return True

    # Means we can accomodate the cows
    return False
        

def GetMaximumMinDistanceBwStalls(stalls: list[int], cows: int)->int:

    if cows > len(stalls):
        return -1
    n = len(stalls)
    stalls.sort()
    lowGap = 1 # minimum gap would be 1
    highGap = stalls[n-1] - stalls[0]
    maxGap = -1

    while lowGap <= highGap:
        mid = lowGap + (highGap - lowGap)//2

        if CanPlaceCow(stalls,mid,cows): # if we can place the cow then we try to increase the gap as we want to maximize it
            maxGap = mid
            lowGap = mid + 1

        else:
            highGap = mid - 1


    return maxGap


stalls = [3,4,7,10,9]
cows = 3

print("Maximum min dsitance",GetMaximumMinDistanceBwStalls(stalls,cows))
