x=int(input())
for _ in range(x):
    s,sg,fg,d,t=map(int,input().split())
    v=((d)*180+s*t)/t
    print(v)
    if abs(sg-v)<abs(fg-v):
        print('SEBI')
    elif abs(fg-v)<abs(sg-v):
        print('FATHER')
    else:
        print('DRAW')
