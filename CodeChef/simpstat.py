x=int(input())
for _ in range(x):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    for i in range(k):
        a.remove(a[0])
    a.sort(reverse=True)
    for i in range(k):
        a.remove(a[0])
    z=sum(a)/len(a)
    print(z)
