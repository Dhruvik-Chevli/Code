x=int(input())
lst=list()
import math
for _ in range(x):
    z=input()
    z=z.split()
    n,m=(int(z[0]),int(z[1]))
    ar=n*m
    i=2
    while True:
        z=ar//i
        if z*i!=ar:
            i+=1
            continue
        t=math.sqrt(z)
        l=int(t)
        if l*l!=z:
            i+=1
            continue
        lst.append(i)
        break
for i in lst:
    print(i)
