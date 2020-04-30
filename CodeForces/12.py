t=int(input())
for _ in range(t):
    li=list(map(int,input().split()))
    if(sum(li)%2):
        print("NO")
    else:
        print("YES)