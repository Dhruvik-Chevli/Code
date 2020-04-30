x=int(input())
for _ in range(x):
    a,b=map(int,input().split())
    if a%2==0 and (b==2*(a/2+1) or b==2*(a/2-1)):
        print('YES')
    elif a%2!=0 and (b==2*(a//2)+3 or b==2*(a//2)-1):
        print('YES')
    elif a%2!=0 and b==a+1:
        print('YES')
    elif a%2==0 and b==a-1:
        print('YES')
    else:
        print('NO')
