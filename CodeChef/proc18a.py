x=int(input())
for _ in range(x):
    n,k=map(int,input().split())
    g=list(map(int,input().split()))
    lst=[]
    i=0
    while i<=n-k:
        f=0
        stat=0
        while f<k:
            stat=stat+g[i+f]
            f+=1
        i+=1
        lst.append(stat)
    lst.sort(reverse=True)
    print(lst[0])
    
