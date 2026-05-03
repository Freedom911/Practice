class TimeMap:

    def __init__(self):
        self.di = {}
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        new_key = key + '_' + str(timestamp)
        self.di[new_key] = value

    def get2(self, key: str, timestamp: int) -> str:
        new_key = key + '_' + str(timestamp)
        if new_key in self.di:
            return self.di[new_key]
        else:
            for i in range(timestamp-1,-1,-1):
                new_key = key + '_' + str(i)
                if new_key in self.di:
                    return self.di[new_key]
        
        return ""

"""
    This is optimized Version SO basically we store  in
    dictionary of list
    so eg key = food,value = 'test',timestamp = 2
    so {key:{value:timestamp}}

    so we push back in vector of a particular key
    now suppose there are three timestamps
    1, 100, 500
    and we have timestamp to find 5
    we basically find the floor same thing
"""
class TimeMap:

    def __init__(self):
        self.di = {} #dictionary of list
        

    def set(self, key: str, value: str, timestamp: int) -> None:
         if key not in self.di:
            self.di[key] = []
         self.di[key].append([value, timestamp])


        

    def get(self, key: str, timestamp: int) -> str:

        if key not in self.di:
            return ""
        
        values = self.di[key]

        n = len(values)

        # now we apply floor logic
        l = 0
        r = n - 1
        res = ""
        
        

        while l <= r:
            mid = l + (r - l)//2
            


            if values[mid][1] == timestamp:
                return values[mid][0]
            
            elif timestamp > values[mid][1]:
                res = values[mid][0]
                l = mid + 1
            else:
                r = mid - 1
        
        
        return res

            
  


timeMap = TimeMap()
timeMap.set("alice", "happy", 1)
#print(timeMap.get("alice", 1))           # return "happy"
print(timeMap.get("alice", 2))          # return "happy", there is no value stored for timestamp 2, 
# thus we return the value at timestamp 1.
timeMap.set("alice", "sad", 3)    # store the key "alice" and value "sad" along with timestamp = 3.
#sprint(timeMap.get("alice", 3))           # return "sad"