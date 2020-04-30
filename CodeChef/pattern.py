n=int(input())
i=1
while i<=n:
    j=1
    while j<=i:
        if i==1:
            print(1,end='')
        elif i!=1:
            if j==1 or j==i:
                print(i-1,end='')
            else:
                print(0,end='')
        j+=1
    print()    
    i+=1
