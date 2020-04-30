n=int(input())
i=0
tr=[]
a=[]
at=[]
c=list(map(int,input().split()))
t=list(map(int,input().split()))
while i<n:
    if t[i]==1:
        tr.append(c[i])
    elif t[i]==2:
        a.append(c[i])
    elif  t[i]==3:
        at.append(c[i])
    i+=1
tr.sort()
a.sort()
at.sort()
if len(tr)==0 or len(a)==0:
    print(at[0])
elif len(at)==0:
    print(tr[0]+a[0])
elif tr[0]+a[0]>at[0]:
    print(at[0])
elif tr[0]+a[0]<=at[0]:
    print(tr[0]+a[0])
