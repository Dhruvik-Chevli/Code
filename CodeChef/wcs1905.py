import sys
def make():
    arr=[[[0 for k in range(55)]for j in range(35)]for i in range(35)]
    #print(arr)
    for i in range(1,35):
        for j in range(1,35):
            for k in range(1,55):
                arr[i][j][k]=sys.maxsize
                if k==i*j:
                    arr[i][j][k]=0
                if k>i*j:
                    continue    
                for l in range(1,i):
                    for t in range(k+1):
                        arr[i][j][k]=min(arr[i][j][k],arr[l][j][t]+arr[i-l][j][k-t]+j**2)
                for l in range(1,j):
                    for t in range(k+1):
                        arr[i][j][k]=min(arr[i][j][k],arr[i][l][t]+arr[i][j-l][k-t]+i**2)
    return arr                            



    
arr=make()
for _ in range(int(input())):
    n,m,k=map(int,input().split())
    print(arr[n][m][k])  
