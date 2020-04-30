x=int(input())
final=''
for _ in range(x):
    flst=[]
    a=[]
    z=input()
    z=z.split()
    z=z[1:]
    for i in z:
        a.append(int(i))
    j=max(a)
    for k in range(len(a)):
        for i in a:
            f=1
            while f==1:
                if i%j!=0:
                    j-=1
                    continue
                f=0
    for m in a:
        y=m/j
        flst.append(int(y))
    for  i in flst:
        final=final+str(i)+' '
    final=final+'\n'
print(final)
