x=int(input())
for _ in range(x):
    a=list(map(int,input().split()))
    m=len(a)
    a.remove(m-1)
    print(max(a))
