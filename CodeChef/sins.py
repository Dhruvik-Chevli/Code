x=int(input())
import math
for _ in range(x):
    x,y=map(int,input().split())
    print(math.gcd(x,y)*2)
