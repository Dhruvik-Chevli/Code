x=int(input())
for _ in range(x):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    c=len(list(set(a).intersection(b)))
    print(c)
