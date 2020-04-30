x=int(input())
flst=[]
for _ in range(x):
    lst=[]
    n=int(input())
    a=input()
    a=a.split()
    for i in a:
        lst.append(int(i))
    m=min(lst)
    cost=m*(len(lst)-1)
    flst.append(cost)
for i in flst:
    print(i)    
