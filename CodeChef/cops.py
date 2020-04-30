x=int(input())
lst=[]
for _ in range(x):
    k=list(range(1,101))
    z=input()
    z=z.split()
    m,x,y=((int(z[0])),(int(z[1])),(int(z[2])))
    n=x*y
    y=input()
    y=y.split()
    for i in range(len(y)):
        a=int(y[i])
        c=a-n
        while c<=a+n:
            if c in k:
                k.remove(c)
            c+=1
    lst.append(len(k))
for i in lst:
    print(i)
