x=int(input())
lst=[]
for _ in range(x):
    X=input()
    Y=input()
    i=0
    f=0
    while i<len(X):
        j=X[i]
        k=Y[i]
        if j!=k and j!='?' and k!='?':
            f=1
            break
        i+=1    
    if f==0:
        lst.append('Yes')
    elif f==1:
        lst.append('No')
for i in lst:
    print(i)
