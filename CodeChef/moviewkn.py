x=int(input())
for _ in range(x):
    n=int(input())
    l=list(map(int,input().split()))
    r=list(map(int,input().split()))
    ind=0
    i=0
    max=0
    while i<n:
        if l[i]*r[i]>max:
            ind=i
            max=l[i]*r[i]
        if l[i]*r[i]==max:
            if r[i]>r[ind]:
                ind=i
        i+=1        
    print(ind+1)
