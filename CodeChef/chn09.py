x=int(input())
lst=[]
for _ in range(x):
    z=input()
    ac=0
    bc=0
    for i in z:
        if i=='a':
            ac=ac+1
        elif i=='b':
            bc=bc+1
    if ac<bc:
        lst.append(ac)
    elif bc<ac:
        lst.append(bc)
    elif ac==bc:
        lst.append(bc)
for i in lst:
    print(i)
