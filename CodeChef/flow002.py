x=int(input())
lst=list()
for i in range(x):
    y=input()
    y=y.split()
    a=int(y[0])
    b=int(y[1])
    c=a%b
    lst.append(c)
for i in lst:
    print(i)
