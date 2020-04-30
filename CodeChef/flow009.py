x=int(input())
lst=[]
for _ in range(x):
    z=input()
    z=z.split()
    q=int(z[0])
    p=float(z[1])
    if q>1000:
        r=0.9*q*p
        lst.append(r)
    else:
        r=q*p
        lst.append(r)
for i in lst:
    print(i)
