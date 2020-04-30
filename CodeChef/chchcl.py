x=int(input())
for _ in range(x):
    n,m=map(int,input().split())
    if n%2==0 or m%2==0:
        print('Yes')
    else:
        print('No')
