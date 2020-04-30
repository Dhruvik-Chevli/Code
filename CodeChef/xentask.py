x=int(input())
for _ in range(x):
    n=int(input())
    x=list(map(int,input().split()))
    y=list(map(int,input().split()))
    t1=0
    t2=0
    i=0
    while i<n:
        if i%2==0:
            t1=t1+x[i]
            t2=t2+y[i]
        elif i%2!=0:
            t1=t1+y[i]
            t2=t2+x[i]
        i+=1
    print(min(t1,t2))        
