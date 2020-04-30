t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    e=0
    o=0
    if len(a)==1:
        print(1)
        continue
    for i in a:
        if i%2==0:
            e+=1
        else:
            o+=1
    if o%2==1:
        print(2)
    else: print(1)
