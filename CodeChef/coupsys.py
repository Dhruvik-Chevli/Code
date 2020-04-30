x=int(input())
for _ in range(x):
    n=int(input())
    x1=None
    x2=None
    x3=None
    c1=None
    c2=None
    c3=None
    for h in range(n):
        c,l,x=map(int,input().split())
        if l==1:
            if x1 is None or x>x1:
                x1=x
                c1=c
            elif x==x1 and c<c1:
                c1=c
        elif l==2:
            if x2 is None or x>x2:
                x2=x
                c2=c
            elif x==x2 and c<c2:
                c2=c
        elif l==3:
            if x3 is None or x>x3:
                x3=x
                c3=c
            elif x==x3 and c<c3:
                c3=c
    print(x1,c1)
    print(x2,c2)
    print(x3,c3)
