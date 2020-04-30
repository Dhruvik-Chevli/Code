x=int(input())
for _ in range(x):
    n=int(input())
    v=list(map(int,input().split()))
    i=0
    min=1000000000000000000000000000000000000
    while i<n-1:
        j=i+1
        while j<=n-1:
            if abs(v[i]-v[j])<min:
                min=abs(v[i]-v[j])
            j+=1
        i+=1
    print(min)
