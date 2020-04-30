x1,y1,x2,y2=map(int,input().split())
if x1==x2:
    if y1==y2:
        rook=0
    else:
        rook=1
elif x1!=x2:
    if y1==y2:
        rook=1
    else:
        rook=2
king=max(abs(x1 - x2), abs(y1 - y2))
if x1!=x2 and y1!=y2:
    if (x1+y1)%2==0 and (x2+y2)%2==0:
        if(abs(x1-x2)//abs(y1-y2)==1):
            bishop=1
        else:
            bishop=2
    elif(x1+y1)%2==1 and (x2+y2)%2==1:
        if(abs(x1-x2)//abs(y1-y2)==1):
            bishop=1
        else:
            bishop=2
    else:
        bishop=0                  
elif(x1==x2 and y1!=y2):
    if (x1+y1)%2==0 and (x2+y2)%2==0:
        bishop=2
    else:
        bishop=0
elif(x1!=x2 and y1!=y2):
    if (x1+y1)%2==0 and (x2+y2)%2==0:
        bishop=2
    else:
        bishop=0          
else:
    bishop=0
print(rook,bishop,king)          


