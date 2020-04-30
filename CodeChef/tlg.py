x=int(input())
p1=0
p2=0
P1=[0]
P2=[0]
for _ in range(x):
    z=input()
    z=z.split()
    a=int(z[0])
    b=int(z[1])
    p1=p1+a
    p2=p2+b
    if p1>p2:
        c=p1-p2
        P1.append(c)
    else:
        c=p2-p1
        P2.append(c)
if max(P1)>max(P2):
    print('1',max(P1))
elif max(P2)>max(P1):
    print('2', max(P2))
