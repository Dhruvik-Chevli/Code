x=int(input())
for _ in range(x):
    x,y=map(int,input().split())
    x=x-y
    if x<0:
        print(0)
    else:
        print(x)
