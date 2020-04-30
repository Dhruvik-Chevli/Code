x=int(input())
lst=list()
for i in range(x):
    z=1
    y=int(input())
    while y>0:
        z=z*y
        y-=1
    lst.append(z)
for i in lst:
    print(i)
    
