x=int(input())
for _ in range(x):
    count=0
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    for i in a:
        if i<k:
            count=count+k-i
        else:
            r=i%k
            count=count+min(r,k-r)
    print(count)
