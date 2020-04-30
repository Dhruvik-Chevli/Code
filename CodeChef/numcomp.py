x=int(input())
for _ in range(x):
    a,b,n=map(int,input().split())
    if  n%2==0:
        if abs(a)>abs(b):
            print(1)
        elif abs(b)>abs(a):
            print(2)
        else:
            print(0)
    if n%2!=0:
        if a>b:
            print(1)
        elif b>a:
            print(2)
        else: print(0)
                                
