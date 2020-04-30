x=int(input())
for _ in range(x):
    n=int(input())
    a=list(map(int, input().split()))
    dc={}
    for i in a:
        dc[i]=dc.get(i,0)+1
    print(len(dc.keys()))
        
