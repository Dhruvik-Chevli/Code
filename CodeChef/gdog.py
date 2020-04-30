x=int(input())
lst=[]
for _ in range(x):
    z=input()
    z=z.split()
    n=int(z[0])
    k=int(z[1])
    mr=None
    k1=k
    while k1>=2:
        if mr is None or mr<n%k1:
            mr=n%k1
        k1-=1
    lst.append(mr)
for i in lst:
    print(i)
