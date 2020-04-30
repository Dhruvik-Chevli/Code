x=int(input())
for _ in range(x):
    cost=0
    n,k=map(int, input().split())
    for i in range(n):
        t,d=map(int, input().split())
        if k>t:
            k=k-t
        elif k<=t:
            t=t-k
            cost=cost+t*d
            k=0
    print(cost)
