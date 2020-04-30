n,q,x=map(int,input().split())
occ=[0 for i in range(n+1)]
li=list(input().split())
for i in range(len(li)):
    for j in li[i]:
        if int(j)==x:
            occ[i+1]+=1
socc=[]
co=0
for i in range(n+1):
    co+=occ[i]
    socc.append(co)
for _ in range(q):
    l,r=map(int,input().split())
    print(socc[r]-socc[l-1])
            
