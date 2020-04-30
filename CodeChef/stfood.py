import sys
for _ in range(int(input())):
    n=int(input())
    ma=-sys.maxsize+1
    for i in range(n):
        s,p,v=map(int,input().split())
        pc=p//(s+1)
        co=pc*v
        if co>ma:
            ma=co
    print(ma)

