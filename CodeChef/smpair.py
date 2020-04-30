x=int(input())
lst=[]
for _ in range(x):
    k=[]
    y=int(input())
    z=input()
    z=z.split()
    for i in z:
        k.append(int(i))
    k.sort()
    a=k[0]+k[1]
    lst.append(a)
for i in lst:
    print(i)
