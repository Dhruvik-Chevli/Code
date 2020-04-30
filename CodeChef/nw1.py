x=int(input())
for _ in range(x):
    z=input().split()
    w=int(z[0])
    s=str(z[1])
    l=w//7
    day=['mon','tues','wed','thurs','fri','sat','sun']
    days=[l,l,l,l,l,l,l]
    j=w%7
    n=day.index(s)
    u=1
    while u<=j:
        days[n]=days[n]+1
        u+=1
        if n==6:
            n=0
        else:
            n+=1    
    dc=''
    for i in days:
        dc=dc+str(i)+' '
    print(dc)
