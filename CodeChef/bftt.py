x=int(input())
for _ in range(x):
    n=int(input())
    n+=1
    while True:
        t=n
        count=0
        while t>0:
            r=t%10
            if r==3:
                count+=1
            t=t//10
        if count>=3:
            print(n)
            break
        else:
            n+=1    
