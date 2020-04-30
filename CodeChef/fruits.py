x=int(input())
lst=[]
for _ in range(x):
    z=input()
    z=z.split()
    n,m,k=(int(z[0]), int(z[1]), int(z[2]))
    while k>0:
        if n>m:
            m=m+1
        elif m>n:
            n=n+1
        elif m==n:
            break
        k-=1
    lst.append(abs(m-n))
for i in lst:
    print(i)
