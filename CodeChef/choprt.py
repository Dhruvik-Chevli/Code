x=int(input())
lst=[]
for _ in range(x):
    z=input()
    z=z.split()
    a=int(z[0])
    b=int(z[1])
    if a>b:
        lst.append('>')
    elif a<b:
        lst.append('<')
    else:
        lst.append('=')
for i in lst:
    print(i)                
