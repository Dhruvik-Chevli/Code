x=int(input())
for _ in range(x):
    s=input()
    k=len(s)
    dc={}
    for i in s:
        dc[i]=dc.get(i,0)+1
    v=dc.values()
    flag=0
    ec=0
    oc=0
    for i in v:
        if i%2==0:
            ec+=1
        elif i%2!=0:
            oc+=1
            if oc>3:
                break
    if oc==0:
        print('!DPS')
    elif k%2==0:
        if oc<=2:
            print('DPS')
        else:
            print('!DPS')
    elif k%2!=0:
        if oc<=3:
            print('DPS')
        else:
            print('!DPS')
