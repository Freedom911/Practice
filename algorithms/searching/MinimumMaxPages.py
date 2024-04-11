class Solution:
    def IsValid(self,books: list[int], k: int, maxPages: int)->bool:
        studentsNeeded = 1
        s = books[0]

        for i in range(1,len(books)):
            s = s + books[i]

            if s > maxPages:
                studentsNeeded = studentsNeeded + 1
                s = books[i]

        if studentsNeeded > k:
            return False
        return True
        
    def shipWithinDays(self,books: list[int], k: int)->int:
    
        if k > len(books):
            return -1
        
        start = max(books)
        minimum = min(books)
        totalPages = sum(books)
        if k == 1:
            return totalPages
        end = totalPages - minimum
        res = -1

        #handling both starting and ending range

        while start <= end:
            mid = start + (end-start)//2

            if self.IsValid(books,k,mid):
                res = mid
                end = mid - 1

            else:
                start = mid + 1

        return res
