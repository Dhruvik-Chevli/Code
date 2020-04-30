x=int(input())
def rev(m):
    reve=0
    while m>0:
        r=m%10
        m=m//10
        reve=reve*10+r
    return(reve)
for _ in range(x):
    n=int(input())
    i=1
    lar=1
    rlar=0
    while i<=n:
        z=rev(i)

        if z>rlar:
            lar=i
            rlar=z
        i+=1
    print(lar)
