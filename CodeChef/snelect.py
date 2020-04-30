x=int(input())
for _ in range(x):
    z=input()
    sn=z.count('s')
    mn=z.count('m')
    i=0
    while i<len(z)-1:
        if z[i]=='s' and z[i+1]=='m':
            sn-=1
            i+=2
        elif z[i]=='m' and z[i+1]=='s':
            sn-=1
            i+=2
        else:
            i+=1
    if sn>mn:
        print('snakes')
    elif mn>sn:
        print('mongooses')
    else:
        print('tie')
