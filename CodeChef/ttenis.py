x=int(input())
for _ in range(x):
    s=input()
    c=0
    o=0
    for i in s:
        if i=='1':
            c+=1
        elif i=='0':
            o+=1
        if c>=10 and o>=10:
            if abs(c-o)==2:
                f=max(c,o)
                if f==c:
                    print('WIN')
                elif f==o:
                    print('LOSE')
        elif c>10 and o<10:
            print('WIN')
        elif c<10 and o>10:
            print('LOSE')
