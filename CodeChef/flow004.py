x=int(input())
lst=[]
for _ in range(x):
    n=int(input())
    f=n%10
    n/=10
    n=int(n)
    while n>0:
        r=n%10
        n/=10
        n=int(n)
    f=f+r
    lst.append(f)
for i in lst:
    print(i)    
