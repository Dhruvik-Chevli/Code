x=int(input())
for _ in range(x):
    a,b=map(int,input().split())
    if a>b:
        sum=''
        while a>0:
            ra=a%10
            a=int(a/10)
            rb=b%10
            b=int(b/10)
            c=(ra+rb)%10
            sum=sum+str(c)
    elif b>=a:
        sum=''
        while b>0:
            rb=b%10
            b=int(b/10)
            ra=a%10
            a=int(a/10)
            c=(ra+rb)%10
            sum=sum+str(c)
    print(sum[::-1])
