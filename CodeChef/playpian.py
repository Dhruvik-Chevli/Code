x=int(input())
for _ in range(x):
    s=input()
    A=0
    B=0
    f=0
    for i in s:
        if i=='A':
            A+=1
        elif i=='B':
            B+=1
        if abs(A-B)>=2:
            f=1
            break
    if f==0:
        print('yes')
    else:
        print('no')
