x=int(input())
for _ in range(x):
    n,k=map(int,input().split())
    s=input()
    up=0
    lo=0
    for i in s:
        if ord(i)>=ord('a') and ord(i)<=ord('z'):
            lo+=1
        elif ord(i)>=ord('A') and ord(i)<=ord('Z'):
            up+=1
    if lo>k and up<=k:
        print('chef')
    elif lo<=k and up>k:
        print('brother')
    elif lo<=k and up<=k:
        print('both')
    elif lo>k and up>k:
        print('none')
                               
