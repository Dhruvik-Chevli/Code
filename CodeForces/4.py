t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    if(sum(a)>sum(b)):
        print("Kashites")
    elif(sum(b)>sum(a)):
        print("Parshites")
    else:
        print("Global Warming")