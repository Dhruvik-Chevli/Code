x=int(input())
d=dict()
for _ in range(x):
    z=input()
    z=z.split()
    a=int(z[0])
    b=int(z[1])
    e=a+b
    g=[a,b]
    f=max(g)
    d[f]=e
for k,v in d.items():
    print(k,v)
