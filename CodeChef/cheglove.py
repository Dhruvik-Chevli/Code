x=int(input())
for _ in range(x):
    n=int(input())
    l=list(map(int,input().split()))
    g=list(map(int,input().split()))
    i=0
    f=0
    while i<n:
        if l[i]<=g[i]:
            i+=1
            continue
        else:
            i+=1
            f=1
            break
    i=0
    u=0
    while i<n:
        if l[i]<=g[n-i-1]:
            i+=1
            continue
        else:
            i+=1
            u=1
            break
    if f==0 and u==1:
        print('front')
    elif f==1 and u==0:
        print('back')
    elif f==0 and u==0:
        print('both')
    else:
        print('none')
