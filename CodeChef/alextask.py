x=int(input())
import math
for _ in range(x):
    n=int(input())
    a=list(map(int,input().split()))
    c=100000000000000000000000000000000000000000000000000000000000000000000
    for i in range(n-1):
        for j in range(i+1,n):
            d=a[i]*a[j]//math.gcd(a[i],a[j])
            if d<c:
                c=d
    print(c)
