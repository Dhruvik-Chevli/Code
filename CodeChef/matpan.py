x=int(input())
for _ in range(x):
    alp=list(map(chr,range(97,123)))
    a=list(map(int,input().split()))
    dc=dict()
    i=0
    for x in alp:
        dc[x]=a[i]
        i+=1
    y=input()
    cost=0
    for z in alp:
        if z not in y:
            cost=cost+dc[z]
    print(cost)
