x=int(input())
lst=[]
for _ in range(x):
    z=int(input())
    if z<1500:
        gs=2*z
    else:
        gs=z+500+0.98*z
    lst.append(gs)
for i in lst:
    print(i)
