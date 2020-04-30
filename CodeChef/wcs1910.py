l,r=map(int,input().split())
a=""
ma=""
for i in range(l):
    a+="0"
#print(a)    
ma="0b"+a[:]
for i in range(r):
    li,ri=map(int,input().split())
    b=""
    for j in range(li-1):
        b+="0"
    for j in range(ri-li+1):
        b+="1"
    for j in range(l-ri):
        b+="0"
    #print(b)
    a="0b"+a    
    b="0b"+b        
    a=bin(int(a,2)^int(b,2))[2:]
    #print(a)
    f="0b"+a
    if (int(f,2)>int(ma,2)):
        ma=a[:]
if len(ma)<l:        
    t=l-len(ma)
    for _ in range(t):
        ma="0"+ma     
print(ma)