u=int(input())
lst=[]
for _ in range(u):
    x=input()
    x=x.split()
    x1,y1,x2,y2=(int(x[0]),int(x[1]),int(x[2]),int(x[3]))
    if x1==x2 and y1<y2:
        lst.append('up')
    elif x1==x2 and y2<y1:
        lst.append('down')
    elif y1==y2 and x2<x1:
        lst.append('left')
    elif y1==y2 and x1<x2:
        lst.append('right')
    else:
        lst.append('sad')
for i in lst:
    print(i)
