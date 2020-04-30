n,q=map(int,input().split())
a=list(map(int,input().split()))
c=min(a)
d=max(a)
for _ in range(q):
    t=int(input())
    if t>=c and t<=d:
        print('Yes')
    else:
        print('No')
