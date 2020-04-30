for k in range(0,int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    for i in range(0,n):
        if l[i]%2==0:
            l[i]=0
        else:
            l[i]=1
    while(l.count(1)>=2):
        l.remove(1)
        l.remove(1)
        l.append(0)
    while(l.count(0)>=2):
        l.remove(0)
    for i in range(0,len(l)):
        l[i]=1
    print(sum(l))
