x=int(input())
for _ in range(x):
    l,b=map(int,input().split())
    i=1
    while True:
        if i%2!=0:
            l=l-i
            if l<0:
                print('Bob')
                break
        elif i%2==0:
            b=b-i
            if b<0:
                print('Limak')
                break
        i+=1
