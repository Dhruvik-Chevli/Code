x=int(input())
lst=[]
for _ in range(x):
    count=0
    z=int(input())
    while z>0:
        r=z%10
        z/=10
        z=int(z)
        if r==4:
            count+=1
    lst.append(count)
for i in lst:
    print(i)            
