x=int(input())
for _ in range(x):
    n=int(input())
    a=list(map(int,input().split()))
    if sum(a)%2!=0:
        print('YES')
    else:
        print('NO')
