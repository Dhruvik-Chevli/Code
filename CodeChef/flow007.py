x=int(input())
lst=list()
def rev(z):
    re=0
    while z>0:
        r=z%10
        z=z/10
        z=int(z)
        re=re*10+r
    return (re)
for i in range(x):
    y=int(input())
    z=rev(y)
    lst.append(z)
for i in lst:
    print(i)
