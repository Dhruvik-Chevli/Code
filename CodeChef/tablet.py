x=int(input())
for _ in range(x):
    n,b=map(int,input().split())
    m=None
    for i in range(n):
        w,h,p=(map(int,input().split()))
        if p<=b:
            ar=w*h
            if m is None or ar>m:
                 m=ar
    if m==None:
        print('no tablet')
    else:
        print(m)
