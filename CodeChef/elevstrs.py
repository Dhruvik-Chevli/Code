x=int(input())
import math
for _ in range(x):
    n,v1,v2=map(int,input().split())
    if n*2/v2>math.sqrt(2)*n/v1:
        print('Stairs')
    elif n*2/v2<math.sqrt(2)*n/v1:
        print('Elevator')
