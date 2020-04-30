x,y=input().split()
w=float(x)
b=float(y)
if w<b and w%5==0:
    r=b-w-0.5
    print(r)
else:
    print(b)
