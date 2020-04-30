x=int(input())
for _ in range(x):
    t=int(input())
    s=list(map(str,input().split()))
    f=1
    for i in range(len(s)-1):
        if s[i]=='cookie'and s[i+1]!='milk':
            f=0
            break
    if s[len(s)-1]=='cookie':
        f=2
    if f==0 or f==2:
        print('NO')
    else:print('YES')
