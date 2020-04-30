x=int(input())
for _ in range(x):
    n,k,s=map(int,input().split())
    s1=1
    count=1
    choc=n
    fl=1
    while s1<=s:
        if choc<k and s1%7!=0:
            choc=choc+n
            count+=1
        choc=choc-k
        s1+=1
        if choc<0:
            fl=0
            break
    if fl==0:
        print(-1)
    elif fl==1:
        print(count)                 
