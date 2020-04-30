x=int(input())
for _ in range(x):
    s=input()
    lst=[]
    i=0
    while i<(len(s)-1):
        lst.append((s[i],s[i+1]))
        i+=2
    f=0
    for i in range(len(lst)-1):
        (x,y)=lst[i]
        if x!=y:
            f=1
            break
    if f==1:
        for i in range(len(lst)-1):
            if lst[i]!=lst[i+1]:
                f=0
                break
    if f==0:
        print('NO')
    elif f==1:
        print('YES')
