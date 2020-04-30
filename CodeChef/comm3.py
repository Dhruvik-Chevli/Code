x=int(input())
import math
lst=[]
for _ in range(x):
    d=int(input())
    a=[]
    for h in range(3):
        z=input()
        z=z.split()
        x=int(z[0])
        y=int(z[1])
        a.append(x)
        a.append(y)
    d1=math.sqrt((a[0]-a[2])**2+(a[1]-a[3])**2)
    d2=math.sqrt((a[2]-a[4])**2+(a[3]-a[5])**2)
    d3=math.sqrt((a[0]-a[4])**2+(a[1]-a[5])**2)
    if (d1>d and d2>d) or (d2>d and d3>d) or (d1>d and d3>d):
        lst.append('no')
    else:
        lst.append('yes')
for i in lst:
    print(i)
