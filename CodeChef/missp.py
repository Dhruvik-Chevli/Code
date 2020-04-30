x=int(input())
lst=[]
for _ in range(x):
    dc={}
    n=int(input())
    for u in range(n):
        z=int(input())
        dc[z]=dc.get(z,0)+1
    for k,v in dc.items():
        if v%2!=0:
            lst.append(k)
            break
for i in lst:
    print(i)                
