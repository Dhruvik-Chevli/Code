x=int(input())
stat=''
import math
def GCD(a,b):
    c=math.gcd(a,b)
    return(c)
def LCM(a,b,f):
    c=a*b/f
    return(int(c))
for _ in range(x):
    k=[]
    z=input()
    z=z.split()
    for i in z:
        k.append(int(i))
    k.sort(reverse=True)
    a=int(k[0])
    b=int(k[1])
    f=GCD(a,b)
    stat=stat+str(f)+' '+str(LCM(a,b,f))+'\n'
print(stat)
