x=int(input())
for _ in range(x):
    stat=''
    n=input().split()
    i=0
    while i<len(n)-1:
        j=n[i].capitalize()
        l=j[0]
        l=l+'.'
        stat=stat+l+' '
        i+=1
    p=n[len(n)-1]
    r=p.capitalize()
    stat=stat+r
    print(stat)
