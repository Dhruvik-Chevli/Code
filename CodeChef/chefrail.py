for _ in range(int(input())):
    n,m=map(int,input().split())
    x=list(map(int,input().split()))
    y=list(map(int,input().split()))
    x=[]
    x1={}
    y1={}
    y2={}
    x2={}
    x0=0
    y0=0
    for i in x:
        if i>0:
            x1[i]=1 
        elif i==0:
            x0=1
        else:
            x2[i]=1
    for i in y:
        if i>0:
            y1[i]=1
        elif i==0:
            y0=1
        else:
            y2[i]=1
    if(x0):
        count=(n-1)*m
    elif(y0):
        count=n*(m-1)
    else:
        count=0
    xpro={}
    for i in x1:
        for j in x2:
            t=abs(i*j)
            xpro[t]=xpro.get(t,0)+1
    ypro={}
    for i in y1:
        for j in y2:
            t=abs(i*j)
            ypro[t]=ypro.get(t,0)+1 
    for i in y:
        count+=xpro.get(i*i,0)
    ypro={}
    for i in x:
        count+=ypro.get(i*i,0)
    print(count)

