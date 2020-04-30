x=int(input())
for _ in range(x):
    n=int(input())
    a=list(map(int,input().split()))
    i=0
    while i<len(a)-1:
        j=i+1
        while j<len(a):
            l=a[i]*a[j]
            if l in a:
                f=1
            elif l not in a:
                f=0
                break
            j+=1
        i+=1
    if f==0:
        print('no')
    elif f==1:
        print('yes')
