x=int(input())
for _ in range(x):
    n,u,d=map(int,input().split())
    j=1
    h=list(map(int,input().split()))
    i=0
    while i<n-1:
        if (h[i+1]>h[i]) and (h[i+1]-h[i]<=u):
            i+=1
            continue
        elif (h[i+1]<h[i]) and (h[i]-h[i+1]<=d):
            i+=1
            continue
        elif (h[i+1]<h[i]) and (h[i]-h[i+1]>d) and j==1:
            j-=1
            i+=1
            continue
        elif h[i+1]==h[i]:
            i+=1
            continue
        else:
            break
    print(i+1)
