x=int(input())
lst=[]
def pal(a):
    r=0
    tot=0
    while a>0:
        r=a%10
        a=a/10
        a=int(a)
        tot=tot*10+r
    return(tot)
for _ in range(x):
    z=int(input())
    k=pal(z)
    if k==z:
        lst.append('wins')
    elif k!=z:
        lst.append('losses')
for i in lst:
    print(i)                
