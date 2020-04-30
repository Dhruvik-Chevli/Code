x=int(input())
lst=[]
for _ in range(x):
    n=int(input())
    i=0
    p=1
    p1=10000000
    if n>1:
        while p<n:
            i+=1
            p=i*(i+1)/2
            p1=(i+1)*(i+2)/2
            if p1>n:
                break
        lst.append(i)
    elif n==1:
        lst.append('1')
for i in lst:
    print(i)
