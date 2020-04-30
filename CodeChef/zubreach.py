x=int(input())
l=0
for _ in range(x):
    stat=''
    m,n=map(int,input().split())
    rx,ry=map(int,input().split())
    z=int(input())
    s=input()
    fx=0
    fy=0
    for i in s:
        if i=='L':
            fx-=1
        elif i=='R':
            fx+=1
        elif i=='U':
            fy+=1
        elif i=='D':
            fy-=1
    l+=1
    stat=stat+'Case '+str(l)+': '
    if fx==rx and fy==ry:
        stat+='REACHED'
    elif fx<0 or fx>m or fy<0 or fy>n:
        stat+='DANGER'
    else:
        stat+='SOMEWHERE'
    print(stat)
