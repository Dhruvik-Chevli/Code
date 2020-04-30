x=int(input())
for _ in range(x):
    p1,p2,k=map(int,input().split())
    z=p1+p2
    if (z//k)%2==0:
        print('CHEF')
    elif (z//k)%2==1:
        print('COOK')    
