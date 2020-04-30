x=int(input())
lst=[]
for _ in range(x):
    k=[]
    z=input()
    z=z.split()
    for i in z:
        k.append(int(i))
    if sum(k)==180:
        lst.append('YES')
    else:
        lst.append('NO')
for i in lst:
    print(i)
