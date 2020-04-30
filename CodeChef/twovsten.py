x=int(input())
for _ in range(x):
    n=int(input())
    i=0
    while n%10!=0:
        n*=2
        i+=1
        if i>2:
            i=-1
            break
    print(i)    
