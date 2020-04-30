x=int(input())
for _ in range(x):
    n=int(input())
    a=list(map(int,input().split()))
    count=0
    l=1
    for i in range(n-1):
        if a[i+1]>=a[i]:
            l+=1
        else:
            count+=l*(l+1)//2
            l=1
    if l>1:
        count+=l*(l+1)//2
    else:
        count=count+1
    print(count)
