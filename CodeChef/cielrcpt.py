x=int(input())
lst=[]
for _ in range(x):
    z=int(input())
    i=11
    count=0
    while z>0:
        j=z/(2**i)
        j=int(j)
        z=z-j*(2**i)
        count=count+j
        i-=1
    lst.append(count)
for i in lst:
    print(i)
