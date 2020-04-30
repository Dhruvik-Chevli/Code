x=int(input())
for _ in range(x):
    n=int(input())
    sq=0
    if n%2==0:
        i=2
        while i<=n:
            sq+=i**2
            i+=2
    elif n%2!=0:
        i=1
        while i<=n:
            sq+=i**2
            i+=2
    print(sq)
