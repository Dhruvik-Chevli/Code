x=int(input())
lst=[]
def sod(x):
    sum=0
    while x>0:
        r=x%10
        x/=10
        x=int(x)
        sum=sum+r
    return(sum)
for i in range(x):
    z=int(input())
    z=sod(z)
    lst.append(z)
for i in lst:
    print(i)
