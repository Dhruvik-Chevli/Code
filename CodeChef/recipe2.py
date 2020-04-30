x=int(input())
stat=''
def GCD(a,b):
    if a%b==0:
        return(b)
    else:
        return(GCD(a,b-1))
for _ in range(x):
    a=[]
    flist=[]
    z=input()
    z=z.split()
    z=z[1:]
    for i in z:
        a.append(int(i))
    b=max(a)
    for i in a:
        b=GCD(i,b)
        for k in a:
            b=GCD(k,b)
    for i in a:
        k=i/b
        k=int(k)
        flist.append(k)
    for i in flist:
        stat=stat+str(i)+' '
    stat=stat+'\n'
stat.rstrip()
print(stat)
