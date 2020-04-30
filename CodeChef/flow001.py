x=int(input())
lst=list()
for i in range(x):
    y=input()
    y=y.split()
    z=int(y[0])
    c=int(y[1])
    lst.append(z+c)
for i in lst:
    print(i)
