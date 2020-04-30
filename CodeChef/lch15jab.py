x=int(input())
flst=[]
for _ in range(x):
    dc={}
    rc=0
    oc=0
    z=input()
    for r in z:
        dc[r]=dc.get(r,0)+1
    tmp=[]
    for k,v in dc.items():
        tmp.append((v,k))
    tmp.sort(reverse=True)
    (v,y)=tmp[0]
    for r in z:
        if r==y:
            rc=rc+1
        else:
            oc=oc+1
    if rc==oc:
        flst.append('YES')
    else:
        flst.append('NO')
for i in flst:
    print(i)
