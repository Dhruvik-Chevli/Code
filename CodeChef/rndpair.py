x=int(input())
for _ in range(x):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    i=0
    lar=-100000
    fl=0
    cnt=0
    while i<len(a)-1:
        j=i+1
        while j< len(a):
            if i<j:
                cnt+=1
                if lar<a[i]+a[j]:
                    lar=a[i]+a[j]
                    fl=1
                elif lar==a[i]+a[j]:
                    fl+=1
            j+=1
        i+=1
    print(fl/cnt)
