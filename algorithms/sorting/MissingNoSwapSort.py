
def find_missing_duplicate(li):
    i = 0

    n = len(li)

    while i < n :
        if li[i] != li[li[i] - 1]:
            j = li[i] - 1
            
            li[i],li[j] = li[j],li[i]
        else:
            i += 1

    for i in range(0,n):
        if li[i] != i + 1:
            print("Duplicate",li[i])
            print("Missing",i + 1)


li = [1,3,2,2,2]
find_missing_duplicate(li)
