x=int(input())
stat=''
for _ in range(x):
    s1=input()
    s2=input()
    i=0
    min=0
    max=0
    while i<len(s1):
        j=s1[i]
        k=s2[i]
        if j==k and j!='?':
            min=min+0
        elif j!=k and (j=='?' or k=='?'):
            min=min+0
        elif j!=k and j!='?' and k!='?':
            min=min+1
        i+=1
    i=0
    while i<len(s1):
        j=s1[i]
        k=s2[i]
        if j==k and j!='?':
            max=max+0
        #elif j!=k and (j=='?' or k=='?'):
        #    max=max+1
        #elif j!=k and j!='?' and k!='?':
        #    max=max+1
        else:
            max=max+1
        i+=1
    stat=stat+str(min)+' '+str(max)+'\n'
print(stat)
