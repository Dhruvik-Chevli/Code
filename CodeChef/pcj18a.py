x=int(input())
for _ in range(x):
    n,x=map(int,input().split())
    a=list(map(int,input().split()))
    f=0
    for i in a:
        if i>=x:
            f=1
            break
    if f==1:
        print('YES')
    else:
        print('NO')             
