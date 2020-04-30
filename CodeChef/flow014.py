x=int(input())
lst=[]
for _ in range(x):
    z=input()
    z=z.split()
    h=int(z[0])
    c=float(z[1])
    t=int(z[2])
    if h>50 and c<0.7 and t>5600:
        lst.append('10')
    elif h>50 and c<0.7 and t<=5600:
        lst.append('9')
    elif h<=50 and c<0.7 and t>5600:
        lst.append('8')
    elif h>50 and c>=0.7 and t>5600:
        lst.append('7')
    elif h<=50 and c>=0.7 and t<=5600:
        lst.append('5')
    else:
        lst.append('6')
for i in lst:
    print(i)
