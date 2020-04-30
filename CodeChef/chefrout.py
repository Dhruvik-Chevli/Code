x=int(input())
for _ in range(x):
    z=input()
    flag=1
    c=0
    s=0
    e=0
    i=0
    while i<len(z)-1:
        if z[i]=='S' and (z[i+1]=='C' or z[i+1]=='E'):
            flag=0
            break
        elif z[i]=='E' and z[i+1]=='C':
            flag=0
            break
        i+=1    
    if flag==1:
        print('yes')
    elif flag==0:
        print('no')
