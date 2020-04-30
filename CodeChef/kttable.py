x=int(input())
lst=[]
for _ in range(x):
    c=[]
    d=[]
    e=[]
    n=int(input())
    a=input()
    b=input()
    a=a.split()
    for i in a:
        c.append(int(i))
    b=b.split()
    for i in b:
        d.append(int(i))
    e.append(c[0])
    i=0
    while i<n-1:
        e.append(c[i+1]-c[i])
        i+=1
    count=0
    i=0
    while i<n:
        if d[i]<=e[i]:
            count+=1
        i+=1
    lst.append(count)
for i in lst:
    print(i)
