x=int(input())
for _ in range(x):
    r=input()
    z=0
    o=0
    for i in r:
        if i=='0':
            z=z+1
        elif i=='1':
            o=o+1
        if z>1 and o>1:
            break
    if z==1 or o==1:
        print('Yes')
    else:
        print('No')
