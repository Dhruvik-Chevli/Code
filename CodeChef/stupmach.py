import sys
for _ in range(int(input())):
    n=int(input())
    li=list(map(int,input().split()))
    curmin=sys.maxsize
    ans=0
    for i in li:
        if i<curmin:
            curmin=i
        ans+=curmin
    print(ans)        
            