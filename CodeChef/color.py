x=int(input())
for _ in range(x):
    n=int(input())
    s=input()
    r=s.count('R')
    g=s.count('G')
    b=s.count('B')
    a=max(r,g,b)
    print(n-a)
