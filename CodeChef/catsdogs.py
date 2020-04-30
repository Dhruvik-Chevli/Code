x=int(input())
for _ in range(x):
    c,d,l=map(int,input().split())
    if l%4!=0:
        print('no')
    elif l/4<=(d+c) and  l/4>=d:
        print('yes')
    elif l/4>(d+c) or l/4<d:
        print('no')
    else:
        print('no')
