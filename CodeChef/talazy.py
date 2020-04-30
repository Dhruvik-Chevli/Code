x=int(input())
for _ in range(x):
    n,b,m=map(int,input().split())
    ql=n
    if n%2==0:
        t=n/2*m
        n=n-n/2
    else:
        t=(n+1)/2*m
        n=(n-1)/2
    t=t+b
    m=2*m
    ql=n
    while ql>0:
        if ql%2==0:
            t=t+ql/2*m
            ql=ql-ql/2
        else:
            t=t+(ql+1)/2*m
            ql=(ql-1)/2
        t+=b
        m=2*m

    print(int(t-b))
