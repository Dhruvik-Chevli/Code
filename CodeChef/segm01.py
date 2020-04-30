x=int(input())
for _ in range(x):
    s=input()
    o=0
    flag=0
    if s[0]=='1':
        o=1
    for i in range(len(s)-1):
        if s[i]=='0' and s[i+1]=='1':
            o+=1
        if o>1:
            break
    if o==1:        
        print('YES')
    else:print('NO')
