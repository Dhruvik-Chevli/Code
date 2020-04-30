x=int(input())
for _ in range(x):
    n,a,b=map(int,input().split())
    x=list(map(int,input().split()))
    z=x.count(a)
    k=x.count(b)
    p1=z/n
    p2=k/n
    print(p1*p2)
