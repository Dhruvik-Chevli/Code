x=int(input())
lst=[]
for _ in range(x):
    y=int(input())
    z=input()
    f=0
    for letter in z:
        if letter=='Y':
            f=1
            break
        elif letter=='I':
            f=2
            break
    if f==0:
        lst.append('NOT SURE')
    elif f==1:
        lst.append('NOT INDIAN')
    elif f==2:
        lst.append('INDIAN')
for i in lst:
    print(i)
