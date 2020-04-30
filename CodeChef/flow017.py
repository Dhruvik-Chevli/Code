x=int(input())
flist=[]
for _ in range(x):
    lst=[]
    z=input()
    z=z.split()
    for i in range(len(z)):
        lst.append(int(z[i]))
    lst.sort()
    flist.append(lst[1])
for i in flist:
    print(i)
