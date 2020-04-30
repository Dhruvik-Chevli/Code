x=int(input())
for _ in range(x):
    n=input()
    k=len(n)
    n=int(n)
    z=10**(k-2)
    l=n%z
    l=n-l-1
    print(l)
