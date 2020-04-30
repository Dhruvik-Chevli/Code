x=int(input())
lst=[]
def sum(a):
    s=a*(a+1)/2
    return(s)
for _ in range(x):
    z=input()
    z=z.split()
    d=int(z[0])
    n=int(z[1])
    while d>0:
        d-=1
        n=sum(n)
    lst.append(int(n))
for i in lst:
    print(i)
