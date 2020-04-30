x=int(input())
for _ in range(x):
    n=int(input())
    s=input()
    h=0
    t=0
    p=1
    for i in s:
        if i=='H':
            h+=1
        elif i=='T':
            t=t+1
        if h-t>1:
            p=0
            break
        if t>h:
            p=0
            break    
    if p==0 or h!=t:
        print('Invalid')
    elif p==1 and h==t:
        print('Valid')
