x=int(input())
lst=[]
for _ in range(x):
    z=int(input())
    if z==[1,2,3]:
        sq=0
    else:
        z=z-2
        z=int(z/2)
        sq=int(z*(z+1)/2)
    lst.append(sq)
for i in lst:
    print(i)
