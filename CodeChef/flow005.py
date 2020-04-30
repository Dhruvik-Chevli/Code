x=int(input())
flst=[]
for _ in range(x):
    z=int(input())
    count=0
    for i in [100,50,10,5,2,1]:
        if z>0:
            j=z/i
            j=int(j)
            z=z-i*j
            count=count+j
    flst.append(count)
for i in flst:
    print(i)            
