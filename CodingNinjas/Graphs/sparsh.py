def getSafePaths(journeys):
    ans=[]
    for journey in journeys:
        j=map(int, input.split(' '))
        stringgetPaths(0,0,j[0],j[1])