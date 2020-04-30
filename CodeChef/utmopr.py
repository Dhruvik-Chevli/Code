x=int(input())
for _ in range(x):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    for i in range(k):
        s=sum(a)+1
        a.append(s)
    if s%2==0:
        print('even')
    else:
        print('odd')
