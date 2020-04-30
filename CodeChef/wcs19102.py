l,r=map(int,input().split())
di={}
for i in range(l):
    di[i+1]=0
ma=0
a=0    
for i in range(r):
    li,ri=map(int,input().split())
    for i in range(li,ri+1):
        if di[i]==0:
            di[i]=1
            a=a+10**(l-i)
        else:
            di[i]=0
            a=a-10**(l-i)
    if a>ma:
        ma=a
ma=str(ma)
print(ma)




