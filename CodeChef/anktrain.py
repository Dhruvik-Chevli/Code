x=int(input())
for _ in range(x):
    n=int(input())
    k=int(n/8)
    if n%8==1:
        p=n+3
        pa=str(p)+'LB'
    elif n%8==2:
        p=n+3
        pa=str(p)+'MB'
    elif n%8==3:
        p=n+3
        pa=str(p)+'UB'
    elif n%8==4:
        p=n-3
        pa=str(p)+'LB'
    elif n%8==5:
        p=n-3
        pa=str(p)+'MB'
    elif n%8==6:
        p=n-3
        pa=str(p)+'UB'
    elif n%8==7:
        p=n+1
        pa=str(p)+'SU'
    elif n%8==0:
        p=n-1
        pa=str(p)+'SL'
    print(pa)            
