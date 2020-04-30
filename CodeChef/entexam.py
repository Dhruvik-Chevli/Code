x=int(input())
for _ in range(x):
    lst=[]
    n,k,e,m=map(int,input().split())
    for f in range(n-1):
        a=list(map(int,input().split()))
        s=sum(a)
        lst.append(s)
    lst.sort(reverse=True)
    j=lst[k-1]
    se=list(map(int,input().split()))
    su=sum(se)
    ma=j-su+1
    if ma>m:
        print('Impossible')
    elif ma<0:
        print('0')
    else:
        print(ma)
