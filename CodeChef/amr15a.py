n=int(input())
elst=[]
olst=[]
k=[]
z=input()
z=z.split()
for i in z:
    k.append(int(i))
for i in k:
    if i%2==0:
        elst.append(i)
    else:
        olst.append(i)
if len(elst)>len(olst):
    print('READY FOR BATTLE')
else:
    print('NOT READY')
