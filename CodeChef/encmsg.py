x=int(input())
import string
for _ in range(x):
    lst=list(string.ascii_lowercase)
    n=int(input())
    z=input()
    j=''
    stat=''
    if len(z)%2==0:
        i=0
        while i<=len(z)-2:
            j+=z[i+1]
            j+=z[i]
            i+=2
    if len(z)%2!=0:
        i=0
        while i<=len(z)-3:
            j+=z[i+1]
            j+=z[i]
            i+=2
        j+=z[n-1]
    i=0
    while i<len(j):
        h=0
        while h<len(lst):
            if lst[h]==j[i]:
                x=h
                break
            h+=1
        k=lst[25-x]
        stat=stat+k
        i+=1
    print(stat)
