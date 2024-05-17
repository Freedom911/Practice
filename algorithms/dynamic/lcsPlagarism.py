
def getPlagarismPercentage(document : list, database : list)->float:
    n = len(document)
    m = len(database)

    # Initializing all to 0
    t = [ [0] * (m + 1) for i in range(n+1)]

    # Main Loop or choice diagram

    for i in range(1,n+1):
        for j in range(1,m+1):
            # Means word matching
            if document[i-1].casefold() == database[i-1].casefold(): # we can add more logic here instead of just copying
                t[i][j] = 1 + t[i-1][j-1]
            else:
                t[i][j] = max(t[i-1][j],t[i][j-1])


    total_matching = t[n][m]
    return (total_matching/n)*100



documentStr = "hello I am you.—In this paper, we explain the concept, characteristics & need of Big Data & different offerings available in the market"
databaseStr = "Hello I are you. I am write the paper so that i can explain the concept and characteristics of need of big data  in market"

print("Plagarism Percentage is = ", round(getPlagarismPercentage(documentStr.split(),databaseStr.split()),2),"%")
