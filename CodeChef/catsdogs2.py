t=int(input())
for i in range(t):
    c,d,l=input().split()
    c=int(c)
    d=int(d)
    l=int(l)
    if (l%4!=0 or l>(c*4+d*4) or l<(d*4)):
        print("no")
    else:
        if (l==(c*4+d*4)):
            print("yes")
        else:
            f=l-(d*4)
            f=(c*4)-f
            if (f<=(d*8)):
                print("yes")
            else:
                print("no")
