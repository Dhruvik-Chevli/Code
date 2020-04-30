x=int(input())
for _ in range(x):
    n,x,s=map(int,input().split())
    lst=[0]*n
    lst[x-1]=1
    for k in range(s):
        a,b=map(int,input().split())
        lst[a-1],lst[b-1]=lst[b-1],lst[a-1]
    z=0
    i=0
    while i<n:
        if lst[i]==1:
            z=i
            break
        i+=1
    print(z+1)
