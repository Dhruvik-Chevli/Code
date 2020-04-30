l,r=map(int,input().split())
ma=0
a=0
for i in range(r):
    li,ri=map(int,input().split())
    b=((1<<(l-ri))-1)^((1<<(l-li+1))-1)
    a=a^b
    if a>ma:
        ma=a
print(bin(ma)[2:])        