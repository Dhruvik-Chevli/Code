x=int(input())
for _ in range(x):
    count=0
    n=int(input())
    for u in range(n):
        s,j=map(int,input().split())
        if j-s>5:
            count+=1
    print(count)        
