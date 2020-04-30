x=int(input())
for _ in range(x):
    n=int(input())
    a=list(map(int,input().split()))
    z=0
    r=0
    for i in a:
        if i==0:
            z+=1
            r=r+1000+100
        elif  i==1:
            if z>0:
                r=r+100
                z+=1
    print(r)                
