x=int(input())
lst=[]
import math
for _ in range(x):
    m,n=[int(l) for l in input().split()]
    gc=math.gcd(m,n)
    f=int(m/gc)*int(n/gc)
    lst.append(f)
for i in lst:
    print(i)
