x=int(input())
sta=''
for i in range(x):
    flist=[]
    y=input()
    y=y.split()
    n=int(y[0])
    k=int(y[1])
    x=input()
    x=x.split()
    comp=[]
    for j in range(k):
        z=input()
        c=z[1:]
        c=c.split()
        comp=comp+c
    for s in x:
        f=0
        for word in comp:
            if s==word:
                f=1
                break
        if f==1:
            flist.append('YES')
        elif f==0:
            flist.append('NO')
    for g in flist:
        sta=sta+' ' +g
    sta=sta+'\n'
print(sta)
