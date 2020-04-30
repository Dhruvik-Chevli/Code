import sys
for _ in range(int(input())):
    n,a,b,c=map(int,input().split())
    mi=sys.maxsize
    li=list(map(int,input().split()))
    #print(a,b,c)
    for i in li:
        t=abs(b-i)+c+abs(i-a)
        #print(t,mi)
        if t<mi:
            mi=t
    print(mi)        