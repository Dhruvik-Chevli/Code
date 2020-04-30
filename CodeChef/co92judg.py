x=int(input())
for _ in range(x):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    am=max(a)
    bm=max(b)
    ai=a.index(am)
    bi=b.index(bm)
    i=0
    a_s=0
    bs=0
    while i<n:
        if i!=ai:
            a_s=a_s+a[i]
        if i!=bi:
            bs=bs+b[i]
        i+=1
    if a_s<bs:
        print('Alice')
    elif bs<a_s:
        print('Bob')
    else:
        print('Draw')
