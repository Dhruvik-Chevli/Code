x=int(input())
lst=[]
for _ in range(x):
    n,m,k=map(int, input().split())
    n=list(range(1,n+1))
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    uu=[]
    ti=[]
    for i in n:
        if i in a and i in b:
            ti.append(i)
        if i not in a and i not in b:
            uu.append(i)
    print(len(ti),len(uu))
