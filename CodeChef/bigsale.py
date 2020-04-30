x=int(input())
for _ in range(x):
    n=int(input())
    loss=0
    for e in range(n):
        p,q,d=map(int,input().split())
        pr=(p+p*d/100)
        loss=loss+(p-(pr-pr*d/100))*q
    print(loss)
