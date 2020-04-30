x=int(input())
for _ in range(x):
    z=input().split()
    n=int(z[0])
    f=str(z[1])
    a=list(map(int,input().split()))
    if f=='Dee' and n==1 and a[0]%2==0:
        print('Dee')
    else:
        print('Dum')
